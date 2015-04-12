/**
 *
 * @author  Francis Ortega 1295578
 * @author  Michal Wozniak 1941097
 * @author  Darren Mau 6057993
 * @author  Francis Cote-Tremblay 6615287
 * @date    03-05-2015
 * @version project v1
 */

#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include "StartupPhase.h"
#include "Country.h"
#include "Player.h"
#include <iostream>
using namespace std;


StartupPhase::StartupPhase() {
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
		Player *tmp = new Player(name);
		players.push_back(*tmp);
	}
	return players;
}

void StartupPhase::initialFortification(vector<Country> *world, list<Player> *players){
	string myStats = "";
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
		string playerName = it->getName();
		cout << endl << playerName << ", prepare to assign your armies. You will have " << nbOfArmies << " armies to assign." << endl;
		for (int i = 0; i < worldSize - 1; i++){
			if (nbOfArmiesAvailable == 0){
				cout << endl << "You have no armies left." << endl;
				break;
			}
			string owner = world->at(i).getOwner();
			if (owner == playerName){
				int inputArmies = 0;
				do {
					if (inputArmies > nbOfArmiesAvailable){
						cout << "The number entered is larger than the number of armies you have. Enter something else..." << endl;
					}
					if (inputArmies < 0){
						cout << "Don't be ridiculous.." << endl;
					}
					cout << "Notice: You have " << nbOfArmiesAvailable << " armies left." << endl;
					cout << "Please enter how many armies to assign to " << world->at(i).getName() << ": " << endl;
					cin >> inputArmies;
				} while (inputArmies > nbOfArmiesAvailable || inputArmies <0 );
				world->at(i).setArmy(inputArmies);
				nbOfArmiesAvailable = nbOfArmiesAvailable - inputArmies;
			}
		}

	}

}

void StartupPhase::assignRandomCountry(vector<Country> *world, list<Player> *players){
	int numOfPlayers = players->size();
	cout << "Players are now being assigned random a country" << endl;

	int i = 0;
	int j = 0;
	
	int numOfCountries = world->size();

	//if the numOfCountries is not divisible by the numOfPlayers, the rest will not be assigned. ex: 42 is not divisible by 4 players, therefore there will be 2 contries left unassigned

	//numOfCountries-numOfPlayers because in the second while loop the index is given by i + j
	while (i<=numOfCountries-numOfPlayers){
		list<Player> playerCopy(*players);
		j = 0;
		while (j < numOfPlayers){
			
			if (playerCopy.size() != 0){
				//generate random number
				srand(time(NULL));
				int randomSelection = rand() % playerCopy.size();

				list<Player>::iterator it = playerCopy.begin();
				//move the it pointer to the "randomSelection"Nth
				advance(it, randomSelection);
				//the value of it contains a player name

				string countryName = world->at(i + j).getName();
				cout << "This country is being assigned a player: " << countryName << endl;

				//the iteration work with the numOfPlayers. for example, if 4 players, then it will assign players to the first 4 country, then to the 5-8 countries, then 9-12, etc
				world->at(i + j).setOwner((*it));
				//world->at(i + j).setArmy(10);

				//after the player name is added, it is deleted from the playerCopy in order avoid searching through the array

				playerCopy.remove((*it));
			}
			j++;
		  }
		i = i + numOfPlayers;
		}

	cout << "Here are the countries and their assigned players:\n";
	cout << "NOTE: if the numOfCountries is not divisible by the numOfPlayers, the rest will not be assigned. ex: 42 is not divisible by 4 players, therefore there will be 2 contries left unassigned and ready to be conquered by anyone" << endl << endl;
	for (int i = 0; i<numOfCountries; i++)

	{
		
		cout << world->at(i).getName() << ": " << world->at(i).getOwner() << endl;

	}
}
