#include "Player.h"
#include "Xe.h"
#include "Ma.h"
#include "Tinh.h"
#include "Tuong.h"
#include "Hau.h"
#include "Tot.h"
#include "../../Utility/StringUtils.h"


Player::Player(bool front):
	_front(front)
{
	init();
}


Player::~Player(void)
{
	for(vector<GameObject*>::iterator iter = objects.begin();iter !=objects.end();iter++)
	{
		delete (*iter);
	}
}


void Player::init()
{
	if(_front)
	{
		objects.push_back(new Xe(ccp(0,0)));
		objects.push_back(new Ma(ccp(0,1)));
		objects.push_back(new Tinh(ccp(0,2)));
		objects.push_back(new Hau(ccp(0,3)));
		objects.push_back(new Tuong(ccp(0,4)));
		objects.push_back(new Tinh(ccp(0,5)));
		objects.push_back(new Ma(ccp(0,6)));
		objects.push_back(new Xe(ccp(0,7)));

		for(int i=0;i<8;i++)
		{
			objects.push_back(new Tot(ccp(1,i)));
		}
	}
	else
	{
		for(int i=0;i<8;i++)
		{
			objects.push_back(new Tot(ccp(6,i)));
		}
		objects.push_back(new Xe(ccp(7,0)));
		objects.push_back(new Ma(ccp(7,1)));
		objects.push_back(new Tinh(ccp(7,2)));
		objects.push_back(new Hau(ccp(7,3)));
		objects.push_back(new Tuong(ccp(7,4)));
		objects.push_back(new Tinh(ccp(7,5)));
		objects.push_back(new Ma(ccp(7,6)));
		objects.push_back(new Xe(ccp(7,7)));

		
	}

}

CCPoint Player::getPoint(string point)
{
	vector<string> elements;
	StringUtils::split(point,',',elements);

	return ccp(atoi(elements[0].c_str()),atoi(elements[1].c_str()));
}

bool Player::isExistObject(CCPoint &point)
{
	GameObject *obj = getObject(point);
	if(obj)
		return true;
	else
	{
		return false;
	}

}

GameObject* Player::getObject(CCPoint &point)
{
	for (int i=0;i<objects.size();i++)
	{
		if(objects[i]->_position.x == point.x && objects[i]->_position.y == point.y)
		{
			return objects[i];
		}
	}
	return NULL;
}

bool Player::play(CCPoint &from,CCPoint &to)
{
	bool success = true;
	GameObject *obj = getObject(from);
	if(obj)
	{
		obj->_position = to;
		return true;
	}
	else
	{
		return false;
	}
}