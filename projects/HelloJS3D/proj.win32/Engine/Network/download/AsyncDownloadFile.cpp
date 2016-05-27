#include "AsyncDownloadFile.h"


#include "cocoa/CCString.h"
#include <errno.h>
#include <stack>
#include <string>
#include <cctype>
#include <queue>
#include <list>
#include "textures/CCTextureCache.h"
#include "curl/curl.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT) && (CC_TARGET_PLATFORM != CC_PLATFORM_WP8)
#include <pthread.h>
#else
#include "CCPThreadWinRT.h"
#include <ppl.h>
#include <ppltasks.h>
using namespace concurrency;
#endif
using namespace std;
USING_NS_CC;

static pthread_t s_loadingThread;

static pthread_mutex_t		s_SleepMutex;
static pthread_cond_t		s_SleepCondition;

static pthread_mutex_t      s_asyncStructQueueMutex;
static pthread_mutex_t      s_ImageInfoMutex;

#ifdef EMSCRIPTEN
// Hack to get ASM.JS validation (no undefined symbols allowed).
#define pthread_cond_signal(_)
#endif // EMSCRIPTEN

static unsigned long s_nAsyncRefCount = 0;

static bool need_quit = false;

static std::queue<AsyncStruct*>* s_pAsyncStructQueue = NULL;
static std::queue<FileInfo*>*   s_pFileQueue = NULL;

size_t fcurl_write(void *ptr, size_t size, size_t nmemb, FILE *stream) {
	return fwrite(ptr, size, nmemb, stream);
} 
static void loadImageData(AsyncStruct *pAsyncStruct)
{
	const char *url = pAsyncStruct->url.c_str();
	const char *fileStore = pAsyncStruct->filePath.c_str();

	CURL *curl = curl_easy_init();
	bool success = true;
	kDownloadResult     downloadResult;
	if (curl) {
		// Open up writable temp graphic.
		FILE *file = fopen(fileStore, "wb");
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fcurl_write);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

		// Write the image to the file.
		int result = curl_easy_perform(curl);
		if (result)
			success = false;
		fclose(file);
		if (success)
		{
			downloadResult = K_RESULT_SUCCESS;
		}
		else
		{
			downloadResult = K_RESULT_DOWNLOAD_ERROR;
		}
	}
	curl_easy_cleanup(curl);

	// generate image info
	FileInfo *pFileInfo = new FileInfo();
	pFileInfo->asyncStruct = pAsyncStruct;
	pFileInfo->downloadResult = downloadResult;
	// put the image info into the queue
	pthread_mutex_lock(&s_ImageInfoMutex);
	s_pFileQueue->push(pFileInfo);
	pthread_mutex_unlock(&s_ImageInfoMutex);
}
static void* networkThread(void* data)
{
	AsyncStruct *pAsyncStruct = NULL;

	while (true)
	{
		// create autorelease pool for iOS
		CCThread thread;
		thread.createAutoreleasePool();

		std::queue<AsyncStruct*> *pQueue = s_pAsyncStructQueue;
		pthread_mutex_lock(&s_asyncStructQueueMutex);// get async struct from queue
		if (pQueue->empty())
		{
			pthread_mutex_unlock(&s_asyncStructQueueMutex);
			if (need_quit) {
				break;
			}
			else {
				pthread_cond_wait(&s_SleepCondition, &s_SleepMutex);
				continue;
			}
		}
		else
		{
			pAsyncStruct = pQueue->front();
			pQueue->pop();
			pthread_mutex_unlock(&s_asyncStructQueueMutex);
		}        
		loadImageData (pAsyncStruct);
	}

	if( s_pAsyncStructQueue != NULL )
	{
		delete s_pAsyncStructQueue;
		s_pAsyncStructQueue = NULL;
		delete s_pFileQueue;
		s_pFileQueue = NULL;

		pthread_mutex_destroy(&s_asyncStructQueueMutex);
		pthread_mutex_destroy(&s_ImageInfoMutex);
		pthread_mutex_destroy(&s_SleepMutex);
		pthread_cond_destroy(&s_SleepCondition);
	}

	return 0;
}
static AsyncDownloadFile *g_sharedTextureCache = NULL;
AsyncDownloadFile * AsyncDownloadFile::shared()
{
	if (!g_sharedTextureCache)
	{
		g_sharedTextureCache = new AsyncDownloadFile();
	}
	return g_sharedTextureCache;
}

AsyncDownloadFile::~AsyncDownloadFile()
{
	CCLOGINFO("cocos2d: deallocing CCTextureCache.");
	need_quit = true;

	pthread_cond_signal(&s_SleepCondition);
}

void AsyncDownloadFile::purgeShared()
{
	CC_SAFE_RELEASE_NULL(g_sharedTextureCache);
}
void AsyncDownloadFile::downloadFileAsync(const char *url, const char *pathStore, cocos2d::CCNode *target, cocos2d::SEL_CallFuncND selector )
{

	CCAssert(url != NULL, "AsyncDownloadFile: url MUST not be NULL");    
	CCAssert(pathStore != NULL, "AsyncDownloadFile: pathStore MUST not be NULL");    

	// lazy init
	if (s_pAsyncStructQueue == NULL)
	{             
		s_pAsyncStructQueue = new queue<AsyncStruct*>();
		s_pFileQueue = new queue<FileInfo*>();        

		pthread_mutex_init(&s_asyncStructQueueMutex, NULL);
		pthread_mutex_init(&s_ImageInfoMutex, NULL);
		pthread_mutex_init(&s_SleepMutex, NULL);
		pthread_cond_init(&s_SleepCondition, NULL);

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT) && (CC_TARGET_PLATFORM != CC_PLATFORM_WP8)
		pthread_create(&s_loadingThread, NULL, networkThread, NULL);
#endif
		need_quit = false;
	}

	if (0 == s_nAsyncRefCount)
	{
		CCDirector::sharedDirector()->getScheduler()->scheduleSelector(schedule_selector(AsyncDownloadFile::loadFileCallBack), this, 0, false);
	}

	++s_nAsyncRefCount;

	if (target)
	{
		target->retain();
	}

	// generate async struct
	AsyncStruct *data = new AsyncStruct();

	data->url = url;
	data->filePath = pathStore;
	data->target = target;
	data->selector = selector;

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT) && (CC_TARGET_PLATFORM != CC_PLATFORM_WP8)
	// add async struct into queue
	pthread_mutex_lock(&s_asyncStructQueueMutex);
	s_pAsyncStructQueue->push(data);
	pthread_mutex_unlock(&s_asyncStructQueueMutex);

	pthread_cond_signal(&s_SleepCondition);
#else
	// WinRT uses an Async Task to load the image since the ThreadPool has a limited number of threads
	//std::replace( data->filename.begin(), data->filename.end(), '/', '\\'); 
	create_task([this, data] {
		loadImageData(data);
	});
#endif
}

void AsyncDownloadFile::loadFileCallBack( float dt )
{
	// the image is generated in loading thread
	std::queue<FileInfo*> *filesQueue = s_pFileQueue;

	pthread_mutex_lock(&s_ImageInfoMutex);
	if (filesQueue->empty())
	{
		pthread_mutex_unlock(&s_ImageInfoMutex);
	}
	else
	{
		FileInfo *pImageInfo = filesQueue->front();
		filesQueue->pop();
		pthread_mutex_unlock(&s_ImageInfoMutex);

		AsyncStruct *pAsyncStruct = pImageInfo->asyncStruct;

		CCNode *target = pAsyncStruct->target;
		SEL_CallFuncND selector = pAsyncStruct->selector;

		if (target && selector)
		{
			(target->*selector)(NULL,(void*)pImageInfo);
			target->release();
		}        

		delete pAsyncStruct;
		delete pImageInfo;

		--s_nAsyncRefCount;
		if (0 == s_nAsyncRefCount)
		{
			CCDirector::sharedDirector()->getScheduler()->unscheduleSelector(schedule_selector(AsyncDownloadFile::loadFileCallBack), this);
		}

	}
}
