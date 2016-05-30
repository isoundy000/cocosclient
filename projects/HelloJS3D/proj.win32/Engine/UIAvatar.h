#pragma once
#include "cocos-ext.h"
#include "cocos2d.h"
#include <string>

USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;
class UIAvatar : public ui::Widget
{
public:
	UIAvatar(void);
	~UIAvatar(void);

	static UIAvatar* create(string id,string url,string defaultImg);
	static UIAvatar* create(string path,string defaultImg);
	static UIAvatar* createWithMask(string path,string defaultImg,string mask);
	
	void setDefaultImage();
	void setTexture(CCTexture2D *texture);
	void setImage(string path);

	CCSize getImageSize();
	void finishDownload(CCNode* node, void* data);

	void asyncExecute();
	void asyncExecuteWithUrl(string id,string url);

protected:

	virtual void initUI(string id,string path,string defaultImg);
	virtual void initUIMask(string id,string path,string defaultImg,string mask);

	virtual void initWithUrl(string id,string url,string defaultImg);
	static std::string filePathFromUrl(const char* id);

	string _url;
	string _defaultImg;
	string _id;
	CCSprite *_img;
	bool _downloading;
};
