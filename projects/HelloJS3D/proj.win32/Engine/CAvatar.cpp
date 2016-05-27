#include "CAvatar.h"
#include "curl/curl.h"
#include "CStringUtils.h"
#include "Network/download/AsyncDownloadFile.h"


CCAvatar* CCAvatar::create(const char* id,const char* url ,const char *default_avatar)
{
	std::string file = filePathFromUrl(id,url).c_str();

	CCAvatar *murray = new CCAvatar();
	std::string strUrl = url;
	if(strUrl.find("https://") != std::string::npos) {
		CStringUtils::replaceAll(strUrl, "https://", "http://");
	}


	CCTexture2D* pTexture = CCTextureCache::sharedTextureCache()->addImage(default_avatar);
	murray->_default_avatar = default_avatar;
	if (std::string::npos != strUrl.find("@NPC"))
	{
		if (murray && murray->initWithTexture(pTexture)) {
			murray->autorelease();
			return murray;
		}
	}

	bool isExistFile =  CCFileUtils::sharedFileUtils()->isFileExist(file);
	//download file ve
	if(!isExistFile && (strcmp("",strUrl.c_str()) != 0))
		AsyncDownloadFile::shared()->downloadFileAsync(strUrl.c_str(),file.c_str(),murray,callfuncND_selector(CCAvatar::finishDownload));
	//set anh avatar
	if (murray && murray->initWithTexture(pTexture)) {
		murray->_imagePath = file;
		murray->autorelease();
		if(isExistFile && strcmp("",strUrl.c_str()) != 0){
			murray->updateImage();
		}
		return murray;
	}

	CC_SAFE_DELETE(murray);
	return NULL;
}

CCAvatar* CCAvatar::create(const char* default_avatar)
{
	CCAvatar *murray = new CCAvatar();
	murray->_default_avatar = default_avatar;
	//set anh avatar
	if (murray && murray->initWithTexture(CCTextureCache::sharedTextureCache()->addImage(default_avatar))) {	
		murray->autorelease();
		return murray;
	}
	CC_SAFE_DELETE(murray);
	return NULL;

}
CCAvatar* CCAvatar::createWithSpriteFrame( const char *frameName )
{
	CCAvatar *pobSprite = new CCAvatar();
	CCSpriteFrame *pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName);
	if (pobSprite && pFrame && pobSprite->initWithSpriteFrame(pFrame))
	{
		pobSprite->autorelease();
		return pobSprite;
	}
	return NULL;
}

void CCAvatar::setImage( const char* id,const char* url)
{
	if(isDownloading)
		return;
	if ((strcmp("",url) == 0))
	{
		return;
	}
	std::string strUrl = url;
	if (std::string::npos != strUrl.find("@NPC"))
	{
		CCSpriteFrame *pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(_default_avatar.c_str());
		this->setDisplayFrame(pFrame);
		return;
	}
	if(strUrl.find("https://") != std::string::npos) {
		CStringUtils::replaceAll(strUrl, "https://", "http://");
	}
	_imagePath = filePathFromUrl(id,strUrl.c_str()).c_str();
	bool isExistFile =  CCFileUtils::sharedFileUtils()->isFileExist(_imagePath);

	//download file ve
	if( !isExistFile )
	{
		AsyncDownloadFile::shared()->downloadFileAsync(strUrl.c_str(),_imagePath.c_str(),this,callfuncND_selector(CCAvatar::finishDownload));
		isDownloading = true;
	}
	else{
		updateImage();
	}
}
void CCAvatar::checkAndSetTexture(CCTexture2D *texture)
{
	if (texture && texture->getContentSize().width > 0 && texture->getContentSize().height >0 )
	{
		this->setTexture(texture);
		this->setTextureCoords(CCRectMake(0,0,texture->getContentSize().width,texture->getContentSize().height));
	}
}
std::string CCAvatar::filePathFromUrl( const char* avatar,const char* url)
{
	std::string dir = CCFileUtils::sharedFileUtils()->getWritablePath();
	char buff[200];
	sprintf(buff,"%s%s%s",dir.c_str(),avatar,".jpg");
	return buff;
}

void CCAvatar::updateImage()
{
	CCTexture2D *texture = CCTextureCache::sharedTextureCache()->textureForKey(_imagePath.c_str());
	if (texture)
	{
		this->checkAndSetTexture(texture);
	}
	else
	{
		this->setTexture(CCTextureCache::sharedTextureCache()->addImage(_default_avatar.c_str()));
		_imagePathWillShow = _imagePath;
		CCTextureCache::sharedTextureCache()->addImageAsync(_imagePathWillShow.c_str(),this,callfuncO_selector(CCAvatar::loadingNCallBack));
	}

}


void CCAvatar::finishDownload(CCNode* node, void* data)
{ 
	FileInfo* fileInfo = (FileInfo*) data;
	if(fileInfo && fileInfo->asyncStruct && fileInfo->downloadResult == K_RESULT_SUCCESS){
		_imagePath = fileInfo->asyncStruct->filePath;
		updateImage();
		isDownloading = false;
	}
}

void CCAvatar::loadingNCallBack(CCObject* object)
{
	CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage(_imagePathWillShow.c_str());
	if (texture)
	{
		this->checkAndSetTexture(texture);
	}
	else
	{
		this->checkAndSetTexture(CCTextureCache::sharedTextureCache()->addImage(_default_avatar.c_str()));
	}
}