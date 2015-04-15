
#include "CountriesStats.h"

#include <list>
#include <string>
#include <map>
#include <iostream>

using namespace std;
CountriesStats::~CountriesStats(){}

string CountriesStats::test(){
	return StatDecorator::test() + " countriesStats";
}

void CountriesStats::printStats(){
	cout << this->myStats << endl;
}

string CountriesStats::getStats(vector<Country> *world, list<string> playerNames) {
	string myStats = "";
	int worldSize = world->size();
	int numOfPlayers = playerNames.size();
	list<string>::iterator it = playerNames.begin();
	map<string, int>::iterator mapIt;
	map<string, int> players;
	//creating map of players
	for (it = playerNames.begin(); it != playerNames.end(); ++it) {
		string playerName = *it;
		players[playerName] = 0;
	}

	for (int i = 0; i < worldSize - 1; i++){

		string owner = world->at(i).getOwner();
		if (owner != ""){
			mapIt = players.find(owner);
			mapIt->second = mapIt->second + 1;
		}
	}
	it = playerNames.begin();
	for (mapIt = players.begin(); mapIt != players.end(); ++mapIt) {
		string playerName = *it;
		myStats = myStats + playerName + "(countries): " + to_string(mapIt->second) + "\n";
		++it;
	}


	this->myStats = StatDecorator::getStats(world, playerNames) + myStats;
	notify();
	return this->myStats;
	
}
