/**
* @author  Francis Ortega 1295578
* @author  Michal Wozniak 1941097
* @author  Darren Mau 6057993
* @author  Francis Cote-Tremblay 6615287
* @date    03-05-2015
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
	bool isLoad = false;
	GamePlay gameTurn;
	Director director;
	GameBuilder* gameRisk = new RiskGameBuilder();
	director.setGameBuilder(gameRisk);
	director.constructGame(&map, &gameTurn);
	Game* risk = director.getGame();
	while(validate == false)
	{
		Map tempMap;
		cout<<"How to implement the map:" << endl;
		cout<<"1. Create your own map." << endl;
		cout<<"2. Load an existing map." << endl;
		cout<<"3. Load game." << endl;
		string temp;
		cin >> temp;
		string temp2 = "";
		//if the user choose to load a map
		if(temp == "2")
		{
			cout<<"Please enter map name: " << endl;

			cin >> temp2;
		}
		else if (temp == "3")
		{
			risk->loadGame();
			map = risk->getMap();
			gameTurn = risk->getGamePlay();
			isLoad = true;
			break;
		}
		validate = editor.createMap(tempMap, temp, temp2);
		if(validate == false)
		{
			cout<< "Map is not connected.\n" <<endl;
		}
		else
		{
			map = tempMap;
		}
	}
	
	vector<Country> *world = map.getWorldMap();
	list<Player> players;
	if(isLoad == false)
	{
		StartupPhase *startupPhase = new StartupPhase(&map);
		players = startupPhase->setPlayerNames();
		//This methos uses rand to assign a random player to a country.
		startupPhase->assignRandomCountry(&players);
		startupPhase->initialFortification(&players);
		cout << world->at(1).getArmy() << endl;
	}
	else
	{
		vector<Player*>* p1 = gameTurn.getPlayers();
		for(int i = 0; i < p1->size(); i++)
		{
			players.push_back(*p1->at(i));
		}
	}

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
	std::list<Player>::iterator player = players.begin();
	if(isLoad)
	{
		for(int i = 1; i < gameTurn.getPlayerTurn(); ++i)
		{
			++player;
		}
	}
	while(players.size() != 1)
	{
		int choice;
		cout<< "Do you want to save game { 0 = yes; 1 = No}" << endl;
		cin >> choice;

		if(choice == 0) // yes
		{
			// Save Game
			vector<Player*>* pl = new vector<Player*>;
			//convert list to vector
			list<Player> playerNames = players;
			while(playerNames.size() != 0)
			{
				Player* p = &playerNames.front();
				playerNames.pop_front();
				pl->push_back(p);
			}
			gameTurn.setPlayers(pl);
			gameTurn.setPlayerTurn(player->getId());
			risk->saveGame();

		}

		while (player != players.end())
		{
			reinforcePhase->reinforcementStart(*player);
			attackPhase->attackPhaseStart(*player);
			fortifyPhase->fortificationStart(*player);

		
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
			for (std::list<Player>::iterator it = players.begin(); it != players.end(); it++)
			{	
				int nbofcuntries = map.getCountryList(it->getName()).size();
				if(nbofcuntries == 0)
				{
					players.erase(it);
					it = players.begin();
				}
			}
			if(player != players.end())
				++player;
		}
		player = players.begin();
	}
	string name = players.front().getName();
	cout<< "Player " << name <<" won the game." << endl;
	delete risk;
	
	system("pause");


	return 0;
}
