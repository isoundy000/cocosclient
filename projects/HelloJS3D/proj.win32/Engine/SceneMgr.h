#pragma once
#include "BaseScene.h"
class SceneMgr
{
public:
	SceneMgr(void);
	~SceneMgr(void);

	enum 
	{
		kEffect_TransitionFade = 1,
		kEffect_TransitionPageForward,
		kEffect_TransitionInOut,
		kEffectFlipYDown,
		kEffectFlipYUp,
		kEffectMoveL,
		kEffectMoveR

	};

	static SceneMgr *sharedSceneMgr();
	static void destroyInstance();
	BaseScene *getRunningScene();

	void replaceScene(BaseScene *scene,int effectTransition = kEffect_TransitionFade);
};

