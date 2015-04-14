#include "GamePlay.h"


GamePlay::GamePlay()
{
	turnCounter= 1;
	gameOver = false;
	//initialize the map
	SaveAndLoad* sl = new SaveAndLoad();
	Map map;
	bool t = sl->load(map, "World.map");
	this->world = map.getWorldMap();

}


GamePlay::~GamePlay()
{
}

/*
1. Getting and placing new armies;
2. Attacking, if you choose to, by rolling the dice;
3. Fortifying your position
*/

void GamePlay::gameFlow()
{




}

/**
 * set the list of player.
 */
void GamePlay::setPlayers(vector<Player*>* players)
{
	this->players = players;
}

/**
 * return the list of player.
 */
vector<Player*>* GamePlay::getPlayers()
{
	return this->players;
}

int GamePlay::getPlayerTurn()
{
	return playerTurn;
}

void GamePlay::setPlayerTurn(int playerTurn)
{
	this->playerTurn = playerTurn;
}
