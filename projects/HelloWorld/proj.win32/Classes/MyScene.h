#pragma once
#include "cocos3d.h"
USING_NS_COCOS3D;

class MyScene : public CCScene
{
public:
	MyScene(void);
	virtual ~MyScene(void);

	virtual bool init();
	CREATE_FUNC(MyScene);
};

class Layer2D : public CCLayer
{
public:
	CREATE_FUNC(Layer2D);
	bool init();

};

class MyScene3D : public CC3Scene
{
public:
	CREATE_FUNC(MyScene3D);
	virtual void initializeScene();
};