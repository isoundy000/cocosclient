#include "BaseScene.h"


BaseScene::BaseScene(void)
{
}


BaseScene::~BaseScene(void)
{
}

BaseScene* BaseScene::create()
{
	BaseScene *pRet = new BaseScene();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

BaseScene* BaseScene::create(BaseLayer *layer)
{
	BaseScene *ret = BaseScene::create();
	if (ret)
	{
		ret->addChild(layer);
	}
	return ret;
}