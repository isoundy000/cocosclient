#ifndef AsyncDownloadFile_h__
#define AsyncDownloadFile_h__

#include "cocos2d.h"

enum kDownloadResult
{
	K_RESULT_SUCCESS,
	K_RESULT_DOWNLOAD_ERROR,
	K_RESULT_WRITE_ERROR
};

typedef struct _AsyncStruct
{
	std::string url;
	std::string            filePath;
	cocos2d::CCNode    *target;
	cocos2d::SEL_CallFuncND        selector;
} AsyncStruct;

typedef struct _FileInfo
{
	AsyncStruct *asyncStruct;
	kDownloadResult     downloadResult;
} FileInfo;

class AsyncDownloadFile: public cocos2d::CCObject
{
public:
	~AsyncDownloadFile();
	static AsyncDownloadFile * shared();
	static void purgeShared();
	void downloadFileAsync(const char *url, const char *pathStore, cocos2d::CCNode *target, cocos2d::SEL_CallFuncND selector);
private:
	void loadFileCallBack(float dt);
};
#endif // AsyncDownloadFile_h__


