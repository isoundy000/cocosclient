#include "GameLogic.h"
#include "Player.h"


GameLogic::GameLogic(void)
{
	init();
}


GameLogic::~GameLogic(void)
{
}


void GameLogic::init()
{
	_front = new Player(true);
	_back = new Player(false);

}

void GameLogic::play(Player *player,CCPoint &from,CCPoint &to)
{

}