/**
*
* @author  Francis Ortega 1295578
* @author  Michal Wozniak 1941097
* @author  Darren Mau 6057993
* @author  Francis Cote-Tremblay 6615287
* @date    03-05-2015
* @version project v1
*/
#include <cstdlib>
#include <iostream>
#include <limits>
#include <map>
#include <vector>
#include <list>
#include <stdlib.h>
#include "SaveAndLoad.h"
#include "Player.h"
#include "StartupPhase.h"
#include "Map.h"
#include "AttackPhase\Battle.h"

using namespace std;

/*
*
*/
int main() {

	//STARTUP PHASE **********************************

	//The number of players will be used throughout the game. It cannot be more than 4
	//at the moment in order to limit the number of countries that need to be used to 
	//run the driver.

	//initialize the map
	SaveAndLoad* sl = new SaveAndLoad();
	Map map;
	bool t = sl->load(map, "World.map");
	vector<Country> *world = map.getWorldMap();


	list<Player> players = StartupPhase::setPlayerNames();
	//This methos uses rand to assign a random player to a country.
	StartupPhase::assignRandomCountry(world, &players);



	//END STARTUP PHASE 
	//MAIN PHASE *****************************************

	//The game will be round robin, but for now countries attack their direct neighbor just for testing purposes.

	int worldSize = world->size();
	Battle battle;

	cout << endl << "Let the battle begin!" << endl << endl;

	for (int i = 0; i < worldSize - 1; i++){
		//cout <<	world->at(i).getOwner() << endl;
		cout << world->at(i).getName() << " will attack " << world->at(i + 1).getName() << endl;
		//battle.war(world->at(i), world->at(i + 1));

	}


	return 0;
}