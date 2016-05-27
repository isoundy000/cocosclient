#pragma once
#include "cocos2d.h"
#include "cocos3d.h"

USING_NS_COCOS3D;
USING_NS_CC;
class TestClass : public CCObject
{
public:
	TestClass(void);
	~TestClass(void);

	void setPosition(CCPoint pos);
	CCPoint getPosition();
protected:
	CCPoint myPos;
};

