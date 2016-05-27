#include "SceneMgr.h"

static SceneMgr *instance = NULL;
SceneMgr::SceneMgr(void)
{
}


SceneMgr::~SceneMgr(void)
{
}

SceneMgr *SceneMgr::sharedSceneMgr()
{
	if (instance == NULL)
	{
		instance = new SceneMgr();
	}
	return instance;
}

void SceneMgr::destroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = NULL;
	}
}


BaseScene* SceneMgr::getRunningScene()
{
	CCDirector *pDirector = CCDirector::sharedDirector();
	return static_cast<BaseScene *>(pDirector->getRunningScene());
}

void SceneMgr::replaceScene(BaseScene *scene,int effectTransition)
{
	CCDirector *pDirector = CCDirector::sharedDirector();
	switch (effectTransition)
	{
	case 0:
		pDirector->replaceScene(scene);
		break;
	case kEffect_TransitionFade:
		pDirector->replaceScene(CCTransitionFade::create(.75,scene));
		break;
	case kEffect_TransitionPageForward:
		pDirector->replaceScene(CCTransitionPageTurn::create(.75,scene,false));
		break;
	case kEffect_TransitionInOut:
		pDirector->replaceScene(CCTransitionProgressInOut::create(.75,scene));
		break;
	case kEffectFlipYDown:
		pDirector->replaceScene(CCTransitionZoomFlipY::create(.5,scene,kCCTransitionOrientationDownOver));
		break;
	case kEffectFlipYUp:
		pDirector->replaceScene(CCTransitionZoomFlipY::create(.5,scene,kCCTransitionOrientationUpOver));
		break;
	case kEffectMoveL:
		pDirector->replaceScene(CCTransitionMoveInL::create(.35,scene));
		break;
	case kEffectMoveR:
		pDirector->replaceScene(CCTransitionMoveInR::create(.35,scene));
		break;
	default:
		break;
	}
	
}