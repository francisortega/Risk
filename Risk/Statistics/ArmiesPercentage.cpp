
#include "ArmiesPercentage.h"

#include <list>
#include <string>
#include <map>
#include <iostream>

using namespace std;
ArmiesPercentage::~ArmiesPercentage(){}

string ArmiesPercentage::test(){
	return StatDecorator::test() + " armiesStats";
}

void ArmiesPercentage::printStats(){
	cout << this->myStats << endl;
}

string ArmiesPercentage::getStats(vector<Country> *world, list<string> playerNames) {
	string myStats = "";
	double totalArmies = 0;
	int worldSize = world->size();
	int numOfPlayers = playerNames.size();
	list<string>::iterator it = playerNames.begin();
	map<string, int>::iterator mapIt;
	map<string, int> players;
	//creating map of players
	for (it = playerNames.begin(); it != playerNames.end(); ++it) {
		string playerName = *it;
		players[playerName]=0;
	}

	for (int i = 0; i < worldSize - 1; i++){

		string owner = world->at(i).getOwner();
		if (owner != ""){
			mapIt = players.find(owner);
			mapIt->second = mapIt->second + world->at(i).getArmy();
			totalArmies = totalArmies + world->at(i).getArmy();
		}
	}
	it = playerNames.begin();
	for (mapIt = players.begin(); mapIt != players.end(); ++mapIt) {
		string playerName = *it;
		double playerArmies = double(mapIt->second);
		double percentage = (playerArmies / totalArmies) * 100;
		myStats = myStats + playerName + "(armies in %): " + to_string(percentage) + "\n";
		++it;
	}

	this->myStats = StatDecorator::getStats(world, playerNames) + myStats;
	notify();
	return this->myStats;

}