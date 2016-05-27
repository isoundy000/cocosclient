#include "UIAvatar.h"

#include "Network/download/AsyncDownloadFile.h"
#include "CStringUtils.h"


UIAvatar::UIAvatar(void) : _downloading(false),_img(NULL)
{
	
}


UIAvatar::~UIAvatar(void)
{
}


UIAvatar *UIAvatar::create(string id,string url,string defaultImg)
{
	UIAvatar *ret = new UIAvatar();
	ret->init();
	ret->autorelease();
	ret->initWithUrl(id,url,defaultImg);

	return ret;
}

UIAvatar* UIAvatar::create(string path,string defaultImg)
{
	UIAvatar *ret = new UIAvatar();
	ret->init();
	ret->autorelease();
	ret->initUI("",path,defaultImg);

	return ret;
}
UIAvatar* UIAvatar::createWithMask(string path,string defaultImg,string mask)
{
	UIAvatar *ret = new UIAvatar();
	ret->init();
	ret->autorelease();
	ret->initUIMask("",path,defaultImg,mask);

	return ret;
}


void UIAvatar::initUI(string id,string path,string defaultImg)
{
	_id = id;
	_defaultImg = defaultImg;
	_img = CCSprite::create(_defaultImg.c_str());
	CCNode::addChild(_img,-1,-1);

	setImage(path);
}


void UIAvatar::initUIMask(string id,string path,string defaultImg,string mask)
{
	_id = id;
	_defaultImg = defaultImg;
	_img = CCSprite::create(_defaultImg.c_str());

	setImage(path);

	CCClippingNode* mCliper = CCClippingNode::create();
	mCliper->setContentSize(_img->getContentSize());
	mCliper->setStencil(_img);
	mCliper->setAnchorPoint(ccp(0,0));

	CCClippingNode *holesClipper = CCClippingNode::create();
	// holesClipper->setInverted(0);
	holesClipper->setAlphaThreshold( 0.1 );
	holesClipper->addChild(_img);
	CCSprite *holeStencil = CCSprite::create(mask.c_str());
	holeStencil->setPosition(ccp(0,0) );

	holesClipper->setStencil( holeStencil);
	mCliper->addChild(holesClipper);
	CCNode::addChild(mCliper,-1,-1);
}

void UIAvatar::initWithUrl(string id,string url,string defaultImg)
{
	_id = id;
	_url = url;
	_defaultImg = defaultImg;

	_img = CCSprite::create(_defaultImg.c_str());
	
	//CCNode::addChild(_img,-1,-1);
	addNode(_img);

	updateAnchorPoint();
	updateRGBAToRenderer(_img);
}

CCSize UIAvatar::getImageSize()
{
	return _img->getContentSize();
}

void UIAvatar::setDefaultImage()
{
	_img->setTexture(CCTextureCache::sharedTextureCache()->addImage(_defaultImg.c_str()));
}

void UIAvatar::setTexture(CCTexture2D *texture)
{
	_img->setTexture(texture);
}

std::string UIAvatar::filePathFromUrl( const char* id)
{
	std::string dir = CCFileUtils::sharedFileUtils()->getWritablePath();
	char buff[200];
	sprintf(buff,"%s%s%s",dir.c_str(),id,".jpg");
	return buff;
}

void UIAvatar::asyncExecute()
{
	std::string strUrl = _url;
	if(strUrl.find("https://") != std::string::npos) {
		CStringUtils::replaceAll(strUrl, "https://", "http://");
	}

	string filecheck = filePathFromUrl(_id.c_str());

	bool isExistFile =  CCFileUtils::sharedFileUtils()->isFileExist(filecheck);
	if(isExistFile)
	{
		setImage(filecheck);
		return;
	}
	//download file ve
	if(!isExistFile && (strcmp("",strUrl.c_str()) != 0))
	{
		AsyncDownloadFile::shared()->downloadFileAsync(strUrl.c_str(),filecheck.c_str(),this,callfuncND_selector(UIAvatar::finishDownload));
		_downloading = true;
	}
		
}

void UIAvatar::asyncExecuteWithUrl(string id,string url)
{
	
	if (!_downloading)
	{
		_id = id;
		_url = url;
		asyncExecute();
	}
}

void UIAvatar::setImage(string path)
{
	setTexture(CCTextureCache::sharedTextureCache()->addImage(path.c_str()));
}

void UIAvatar::finishDownload(CCNode* node, void* data)
{ 
	_downloading = false;
	FileInfo* fileInfo = (FileInfo*) data;
	if(fileInfo && fileInfo->asyncStruct && fileInfo->downloadResult == K_RESULT_SUCCESS){
		string _imagePath = fileInfo->asyncStruct->filePath;
		setImage(_imagePath);
	}
}
