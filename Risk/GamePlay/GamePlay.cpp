#include "GamePlay.h"


GamePlay::GamePlay()
{
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
