/**
*
* @author  Francis Ortega 1295578
* @author  Michal Wozniak 1941097
* @author  Darren Mau 6057993
* @author  Francis Cote-Tremblay 6615287
*/

#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include "StartupPhase.h"
#include "../Map/Country.h"
#include "../Player/Player.h"
#include <iostream>
using namespace std;


StartupPhase::StartupPhase(Map *map) {
	this->currentMap = map;
}

StartupPhase::StartupPhase(const StartupPhase& orig) {
}

StartupPhase::~StartupPhase() {
}

list<Player> StartupPhase::setPlayerNames(){
	int numOfPlayers = 0;

	cout << "How many players? (Max 4 players)\n";
	cin >> numOfPlayers;
	while (numOfPlayers <= 0 || numOfPlayers>4 || !cin.good()){
		cout << "Enter an integer between 1 and 4\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> numOfPlayers;
	}

	list<Player> players;

	string name;
	//This sets the name of each player.
	for (int i = 1; i <= numOfPlayers; i++){
		cout << "Enter player " << i << " name:\n";
		cin >> name;
		Player *tmp = new Player(name, i);
		players.push_back(*tmp);
	}
	return players;
}

void StartupPhase::initialFortification(list<Player> *players){
	vector<Country> *world = currentMap->getWorldMap();
	int worldSize = world->size();
	int numOfPlayers = players->size();
	list<Player>::iterator it = players->begin();
	map<string, int>::iterator mapIt;

	int nbOfArmies = 0;
	if (numOfPlayers == 2){
		nbOfArmies = 40;
	}
	if (numOfPlayers == 3){
		nbOfArmies = 35;
	}
	if (numOfPlayers == 4){
		nbOfArmies = 30;
	}

	for (it = players->begin(); it != players->end(); ++it) {
		int nbOfArmiesAvailable = nbOfArmies;
		bool conditionBroken = false;
		string playerName = it->getName();
		vector<Country> ownerCountries = currentMap->getCountryList(playerName);
		int countriesLeftToSet = ownerCountries.size();
		
		cout << endl << playerName << ", prepare to assign your armies. You will have " << nbOfArmies << " armies to assign." << endl;

		for (int i = 0; i < worldSize - 1; i++){
			
			if (nbOfArmiesAvailable <= 0){
				cout << endl << "You have no armies left." << endl;
				break;
			}
			string owner = world->at(i).getOwner();
			
			if (owner == playerName){
				int inputArmies = 0;

				do {
					cout << "Notice: You have " << nbOfArmiesAvailable << " armies left and " << countriesLeftToSet << " countries left to assign armies" << endl;
					cout << "Please enter how many armies to assign to " << world->at(i).getName() << ": " << endl;
					cin >> inputArmies;
					conditionBroken = false;
					if (inputArmies > nbOfArmiesAvailable){
						cout << "The number entered is larger than the number of armies you have. Enter something else..." << endl;
						conditionBroken = true;
					}
					else if (inputArmies < 0){
						cout << "Dont be ridiculous.." << endl;
					}
					else if (nbOfArmiesAvailable - inputArmies <= countriesLeftToSet){
						cout << "You have to have at least one army per country." << endl;
						conditionBroken = true;
					}
					
					
				} while (conditionBroken);
				world->at(i).setArmy(inputArmies);
				nbOfArmiesAvailable = nbOfArmiesAvailable - inputArmies;
				--countriesLeftToSet;

				if (countriesLeftToSet == 0 && nbOfArmiesAvailable > 0){
					cout << "There were some remaining armies left to set. They were set to your last country." << endl;
					world->at(i).setArmy(world->at(i).getArmy() + nbOfArmiesAvailable);
				}
			}
		}

	}

}

void StartupPhase::assignRandomCountry(list<Player> *players){
	vector<Country> *world = currentMap->getWorldMap();
	int numOfPlayers = players->size();
	cout << "Players are now being assigned random a country" << endl;

	int i = 0;

	int numOfCountries = world->size();
	
	//in order not to modify players, We create a list<string> with only the playerNames
	list<string> playerNames = createPlayerNames(players);
	//if the numOfCountries is not divisible by the numOfPlayers, the rest will not be assigned. ex: 42 is not divisible by 4 players, therefore there will be 2 contries left unassigned
	list<string> playerCopy(playerNames);
	while (i < numOfCountries ){	

		if (playerCopy.size() == 0){
			for (string player : playerNames){
				playerCopy.push_back(player);
			}
		}
				//generate random number
				srand(time(NULL));
				int randomSelection = rand() % playerCopy.size();

				list<string>::iterator it = playerCopy.begin();
				//move the it pointer to the "randomSelection"Nth
				advance(it, randomSelection);
				//the value of it contains a player name

				string countryName = world->at(i).getName();
				cout << "This country is being assigned a player: " << countryName << endl;

				//the iteration work with the numOfPlayers. for example, if 4 players, then it will assign players to the first 4 country, then to the 5-8 countries, then 9-12, etc
				world->at(i).setOwner((*it)); ///ERROR HERE (*it) need to change stuff in country in map 
				//world->at(i + j).setArmy(10);

				//after the player name is added, it is deleted from the playerCopy in order avoid searching through the array

				playerCopy.erase(it);
			
		
		++i;
	}

	cout << "Here are the countries and their assigned players:\n";
	cout << "NOTE: if the numOfCountries is not divisible by the numOfPlayers, the rest will not be assigned. ex: 42 is not divisible by 4 players, therefore there will be 2 contries left unassigned and ready to be conquered by anyone" << endl << endl;
	for (int i = 0; i<numOfCountries; i++)

	{

		cout << world->at(i).getName() << ": " << world->at(i).getOwner() << endl;

	}
}


list<string> StartupPhase::createPlayerNames(list<Player> *players){
	list<string> playerNames;
	for (Player player : *players){
		playerNames.push_back(player.getName());
	}
	return playerNames;
}