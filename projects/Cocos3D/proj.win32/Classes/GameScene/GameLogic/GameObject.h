#pragma once
#include "cocos2d.h"

USING_NS_CC;
class GameObject
{
public:
	enum Type
	{
		kTot,
		kXe,
		kTinh,
		kMa,
		kHau,
		kTuong
	};
	GameObject(GameObject::Type type);
	~GameObject(void);

	CCPoint _position;
	GameObject::Type _type;
	bool _eated;
	cocos2d::ccColor3B _color;

	virtual void advance(){};
	CC_SYNTHESIZE(void*,userData,UserData);

};

