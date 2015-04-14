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
#include "Player/Player.h"
#include "Phases/StartupPhase.h"
#include "Map/Map.h"
#include "Phases\Battle.h"
#include "Phases\AttackPhase.h"
#include "Phases\ReinformentPhase.h"
#include "Phases/FortificationPhase.h"
#include "Game\Director.h"
#include "Game\Game.h"
#include "Game\GameBuilder.h"
#include "Game\RiskGameBuilder.h"
#include "Editor\MapEditor.h"

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
	MapEditor editor;
	Map map;
	bool validate = false;
	while(validate == false)
	{
		cout<<"How to implement the map:" << endl;
		cout<<"1. Create your own map." << endl;
		cout<<"2. Load an existing map." << endl;
		string temp;
		cin >> temp;
		string temp2 = "";
		//if the user choose to load a map
		if(temp == "2")
		{
			cout<<"Please enter map name: " << endl;
			cin >> temp2;
		}
		validate = editor.createMap(map, temp, temp2);
		if(validate == false)
		{
			cout<< "Map is not connected." <<endl;
		}
	}
	
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

	cout << endl << "Let the battle begin!" << endl << endl;

	/*for (int i = 0; i < worldSize - 1; i++){
		//cout <<	world->at(i).getOwner() << endl;
		cout << world->at(i).getName() << " will attack " << world->at(i + 1).getName() << endl;
		battle.war(, world->at(i), world->at(i + 1));

	}*/

	AttackPhase *attackPhase = new AttackPhase(&map);
	ReinforcementPhase *reinforcePhase = new ReinforcementPhase(&map);
	Fortification *fortifyPhase = new Fortification(&map);
	/*
	for (Player player : players){
		reinforcePhase->reinforcementStart(player);
		attackPhase->attackPhaseStart(player);
		fortifyPhase->fortificationStart(player);
	}
	*/
	// Save Game
	GamePlay gameTurn;
	vector<Player*>* pl = new vector<Player*>;
	//convert list to vector
	list<Player> playerNames = players;
	while(playerNames.size() != 0)
	{
		string name = playerNames.front().getName();
		playerNames.pop_front();
		Player* p = new Player();
		p->setName(name);
		//Randomly add 2 cards for each players to test.
		p->getCards()->add();
		p->getCards()->add();
		pl->push_back(p);
	}
	
	gameTurn.setPlayers(pl);
	gameTurn.setPlayerTurn(2);
	Director director;
	GameBuilder* gameRisk = new RiskGameBuilder();
	director.setGameBuilder(gameRisk);
	director.constructGame(&map, &gameTurn);
	Game* risk = director.getGame();
	//risk->saveGame();
	risk->loadGame();
	map = risk->getMap();
	gameTurn = risk->getGamePlay();
	pl = gameTurn.getPlayers();
	for(int i = 0; i < pl->size(); i++)
	{
		cout << pl->at(i)->getName() << ": " << pl->at(i)->getCards()->getCardList()->front() << endl;
	}

	delete gameRisk;
	for(int i = 0; i < pl->size(); ++i)
	{
		delete pl->at(i);
	}
	delete risk;
	system("pause");


	return 0;
}
