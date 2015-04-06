/**
 *
 * @author  Francis Ortega 1295578
 * @author  Michal Wozniak 1941097
 * @author  Darren Mau 6057993
 * @author  Francis Cote-Tremblay 6615287
 * @date    03-05-2015
 * @version project v1
 */
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <list>
#include "StartupPhase.h"
#include "Country.h"
using namespace std;


StartupPhase::StartupPhase() {
}

StartupPhase::StartupPhase(const StartupPhase& orig) {
}

StartupPhase::~StartupPhase() {
}

void StartupPhase::assignRandomCountry(vector<Country> &world, list<string> playerNames, const int numOfPlayers){

	cout << "Players are now being assigned random a country" << endl;

	int i = 0;
	int j = 0;
	
	int numOfCountries = world.size();

	//if the numOfCountries is not divisible by the numOfPlayers, the rest will not be assigned. ex: 42 is not divisible by 4 players, therefore there will be 2 contries left unassigned

	//numOfCountries-numOfPlayers because in the second while loop the index is given by i + j
	while (i<=numOfCountries-numOfPlayers){
		list<string> playerCopy(playerNames);
		j = 0;
		while (j < numOfPlayers){
			
			if (playerCopy.size() != 0){
				//generate random number
				srand(time(NULL));
				int randomSelection = rand() % playerCopy.size();

				list<string>::iterator it = playerCopy.begin();
				//move the it pointer to the "randomSelection"Nth
				advance(it, randomSelection);
				//the value of it contains a player name

				string countryName = world[i + j].getName();
				cout << "This country is being assigned a player: " << countryName << endl;

				//the iteration work with the numOfPlayers. for example, if 4 players, then it will assign players to the first 4 country, then to the 5-8 countries, then 9-12, etc
				world[i + j].setOwner((*it));
				world[i+ j].setArmy(10);

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

		cout << world[i].getName() << ": " << world[i].getOwner() << endl;

	}
}
