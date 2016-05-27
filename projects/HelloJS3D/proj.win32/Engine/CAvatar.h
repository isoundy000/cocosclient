#ifndef CAvatar_h__
#define CAvatar_h__
#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
class CCAvatar:
	public CCSprite
{
public:

	CCAvatar(){
		isDownloading = false;
	}

	static CCAvatar* create(const char* id,const char* url,const char *default_avatar);
	static CCAvatar* create(const char* default_avatar);
	static CCAvatar* createWithSpriteFrame(const char *frameName);
	static std::string filePathFromUrl(const char* avatar,const char* url);
	static std::string getCacheFolder();

	void setImage(const char* avatar,const char* url);
	void updateImage();
	void checkAndSetTexture(CCTexture2D *texture);
	void finishDownload(CCNode* node, void* data);
	void loadingNCallBack(CCObject* object);
private:
	std::string _imagePath;
	std::string _imagePathWillShow;

	bool isDownloading;
public:
	std::string _default_avatar;
};
#endif // CAvatar_h__
