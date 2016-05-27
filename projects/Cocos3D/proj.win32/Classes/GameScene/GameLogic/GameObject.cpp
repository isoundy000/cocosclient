#include "GameObject.h"


GameObject::GameObject(GameObject::Type type)
{
	_type = type;
	_position = ccp(0,0);
	_eated = false;
	_color = ccc3(0,0,0);
}


GameObject::~GameObject(void)
{
}
