#pragma once
#include "Player.h"
class GameLogic
{
public:
	GameLogic(void);
	~GameLogic(void);

	Player *_front;
	Player *_back;

	void play(Player *player,CCPoint &from,CCPoint &to);
	
protected:
	void init();
};

