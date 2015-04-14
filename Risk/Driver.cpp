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
#include "Player\Player.h"
#include "Phases\StartupPhase.h"
#include "Map\Map.h"
#include "Phases\Battle.h"
#include "Phases\AttackPhase.h"
#include "Phases\ReinformentPhase.h"
#include "Phases\FortificationPhase.h"
#include "Statistics\PlayerView.h"
#include "Statistics\ArmiesPercentage.h"
#include "Statistics\CountriesPercentage.h"
#include "Statistics\ArmiesStats.h"
#include "Statistics\CountriesStats.h"

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
	
	StartupPhase *startupPhase = new StartupPhase(&map);
	list<Player> players = startupPhase->setPlayerNames();
	//This methos uses rand to assign a random player to a country.
	startupPhase->assignRandomCountry(&players);
	startupPhase->initialFortification(&players);
	cout << world->at(1).getArmy() << endl;

	//END STARTUP PHASE 
	//MAIN PHASE *****************************************

	//The game will be round robin, but for now countries attack their direct neighbor just for testing purposes.

	int worldSize = world->size();
	Battle battle;

	//create playerNames list for the observer-decorator
	list<string> playerNames;
	for (Player player : players){
		playerNames.push_back(player.getName());
	}


	cout << endl << "Let the battle begin!" << endl << endl;

	AttackPhase *attackPhase = new AttackPhase(&map);
	ReinforcementPhase *reinforcePhase = new ReinforcementPhase(&map);
	Fortification *fortifyPhase = new Fortification(&map);
	
	for (Player player : players){
		reinforcePhase->reinforcementStart(player);
		attackPhase->attackPhaseStart(player);
		fortifyPhase->fortificationStart(player);


		cout << "observer-decorator part" << endl;
		//the undecorated statistics is only "The statistics are:"
		PlayerView *pv = new PlayerView();
		pv->stat->attach(pv);
		//adding first decorator
		pv->stat->detach(pv);
		pv->stat = new ArmiesStats(pv->stat);
		pv->stat->attach(pv);
		pv->stat->getStats(world, playerNames);
		//adding second decorator
		pv->stat->detach(pv);
		pv->stat = new ArmiesPercentage(pv->stat);
		pv->stat->attach(pv);
		pv->stat->getStats(world, playerNames);
		//adding third decorator
		pv->stat->detach(pv);
		pv->stat = new CountriesStats(pv->stat);
		pv->stat->attach(pv);
		pv->stat->getStats(world, playerNames);
		//adding fourth decorator
		pv->stat->detach(pv);
		pv->stat = new CountriesPercentage(pv->stat);
		pv->stat->attach(pv);
		pv->stat->getStats(world, playerNames);

	}
	system("pause");


	return 0;
}