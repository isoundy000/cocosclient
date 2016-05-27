#pragma once 

#include "cocos2d.h"
#include "BaseLayer.h"

USING_NS_CC;
class BaseScene;
class BaseLayer;
#define CREATE_SCENE(_LAYER_) \
	static BaseScene *makeScene() \
{ \
	BaseScene* ret = BaseScene::create(); \
	_LAYER_ *layer = _LAYER_::create(); \
	ret->addChild(layer); \
	return ret;	\
}

class BaseScene : public CCScene
{
public:
	BaseScene(void);
	~BaseScene(void);

	static BaseScene* create();
	static BaseScene* create(BaseLayer *layer);
};

