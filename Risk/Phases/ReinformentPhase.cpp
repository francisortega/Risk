#include "ReinformentPhase.h"
#include "map"
#include <iostream>
using namespace std;

ReinforcementPhase::ReinforcementPhase(Map *map)
{
	this->currentMap = map;
}

ReinforcementPhase::~ReinforcementPhase()
{

}

void ReinforcementPhase::reinforcementStart(Player&player)
{
	cout << "---------- Reinforcement Phase Start for : " << player.getName() << "----------" << endl;
	addMoreTroops(player);
}

/*
	This function will add more trop -> the quantity will depend on multiple factors like number of country owned, nb of card used ...
	*/
void ReinforcementPhase::addMoreTroops(Player &player)
{
	int bonusArmiesFromCard = consumeCards(player);
	int bonusArmiesFromCountry = bonusArmiesFromCountries(&player);
	int bonusArmiesFromContinent = bonusArmiesFromContinents(&player);
	
	reinforceWithNewTroop(bonusArmiesFromCard + bonusArmiesFromCountry + bonusArmiesFromContinent, &player);

}

int ReinforcementPhase::bonusArmiesFromCountries(Player *player)
{
	vector<Country> list = currentMap->getCountryList(player->getName());
	int size = list.size();
	double doubleSize = (double)size;
	double doubleArmies = doubleSize / 3;
	int newArmies = (int)doubleArmies;
	
	return newArmies;
}

int ReinforcementPhase::bonusArmiesFromContinents(Player *player){
	std::vector<Map::Continent> continents = currentMap->getContinents();
	string playerName = player->getName();
	int bonusArmies = 0;
	bool allCountries = true;
	for (Map::Continent continent : continents){
		allCountries = true;
		vector<Country> countries = currentMap->getCountriesOfContinents(continent.name);

		for (Country country : countries){
			if (country.getOwner() != playerName){
				allCountries = false;
			}
		}
		if (allCountries){
			if (continent.name == "asia"){
				bonusArmies +=7;
			}
			else if (continent.name == "north america"){
				bonusArmies += 5;
			}
			else if (continent.name == "europe"){
				bonusArmies +=5;
			}
			else if (continent.name == "africa"){
				bonusArmies += 3;
			}
			else if (continent.name == "australia"){
				bonusArmies += 2;
			}
			else if (continent.name == "south america"){
				bonusArmies += 2;
			}

		}

	}
	return bonusArmies;

}

int ReinforcementPhase::consumeCards(Player &player)
{
	player.playerCard.verifyTradeInPosibility(); // do verification update stats
	if (player.playerCard.isTradeInPossibleNow()) // if true
	{
		if (player.playerCard.mustTradeInNow()) // forced to tradein
		{
			return cardSelection(player.playerCard); // bonus army from consuming cards
		}
		else //optional trade
		{
			int choice;
			do{
				cout << "Do you want do want to trade 3 cards {0 = Yes/1 = No}" << endl;
				cin >> choice;
			} while (choice > 1 || choice < 0);

			if (choice = 0) //yes
			{
				return cardSelection(player.playerCard); // bonus army from consuming cards
			}
			else
				return 0;
		}
	}
	else
		return 0;
	
}

int ReinforcementPhase::cardSelection(Cards playerCards)
{
	int selection1, selection2, selection3;
	playerCards.viewCardsList();  // print player cards
	cout << "Select your 3 cards that you wish to trade In {Write  0 for Infantry - 1 for Cavalry - 2 for Artillery}" << endl;
	do{
		cout << "First card selected : " << endl;
		cin >> selection1;
	} while (selection1 > 3 || selection1 < 0);
	do{
		cout << "Second card selected : " << endl;
		cin >> selection2;
	} while (selection2 > 3 || selection2 < 0);
	do{
		cout << "Third card selected : " << endl;
		cin >> selection3;
	} while (selection3 > 3 || selection3 < 0);

	int armyFromCard = playerCards.getNextCardTradeInArmyValue();
	//deleted used card from cardlist
	playerCards.doTradeIn(selection1, selection2, selection3);

	return armyFromCard;

}

void ReinforcementPhase::reinforceWithNewTroop(int nbOfArmies, Player *player)
{
	cout << "Assign all your new available troop ";

	///FRANCIS METHOD!!! 
	vector<Country> *world = this->currentMap->getWorldMap();
	int worldSize = world->size();
	map<string, int>::iterator mapIt;

	string playerName = player->getName();
	cout << endl << playerName << ", prepare to assign your armies. You will have " << nbOfArmies << " armies to assign." << endl;

	int nbOfArmiesAvailable = nbOfArmies;
	for (int i = 0; i < worldSize - 1; i++){
		if (nbOfArmiesAvailable <= 0){
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
			} while (inputArmies > nbOfArmiesAvailable || inputArmies < 0);
			world->at(i).setArmy(world->at(i).getArmy() + inputArmies);
			nbOfArmiesAvailable = nbOfArmiesAvailable - inputArmies;
		}
	}




}

