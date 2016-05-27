#pragma once
#include <map>
#include "cocos2d.h"
#include "GameObject.h"

using namespace std;
USING_NS_CC;
class Player
{
public:
	
	Player(bool front);
	~Player(void);

	bool _front;
	vector<GameObject*> objects;
	bool play(CCPoint &from,CCPoint &to);
	bool isExistObject(CCPoint &point);
	GameObject *getObject(CCPoint &point);

protected:
	void init();
	CCPoint getPoint(string point);

};

