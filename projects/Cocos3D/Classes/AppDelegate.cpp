#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "cocos3d.h"

USING_NS_COCOS3D;
USING_NS_CC;
#include <string>

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {

    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

	//pDirector->getOpenGLView()->setDesignResolutionSize(800,480,kResolutionFixedHeight);


	CCSize viewSize = CCDirector::sharedDirector()->getWinSizeInPixels();
	GLfloat deviceFactor = MAX(viewSize.height, viewSize.width) / 480.f;
	CCLOG( "Device Factor: %.2f", deviceFactor );
	//CCDirector::sharedDirector()->setContentScaleFactor(viewSize.height / 480);


	/////////////////////////////////    3D init
	//CLoggers* logMgr = CLoggers::sharedLoggers();
	//logMgr->addLogger( this );
	CC3ActionManager::active();
	Cocos3d::startUp( false );
	Cocos3d::addInternalShaderPaths();
	//////////////////////////////////////

    // create a scene. it's an autorelease object
    CCScene *pScene = HelloWorld::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
