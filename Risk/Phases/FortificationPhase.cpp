#include "FortificationPhase.h"
#include <iostream>
using namespace std;

Fortification::Fortification(Map *map)
{
	this->currentMap = map;
}


Fortification::~Fortification()
{
}


void Fortification::fortificationSetup(Player& player)
{
	int choice;
	do{
		cout << "Do you wish to fortify? { 0 = YES; 1 = NO} " << endl;
		cin >> choice;
	} while (choice != 0 || choice != 1);

	if (choice == 0)
	{
		fortificationStart(player);
		player.playerCard.resetAlreadyCaptureOneCountry();
	}
	//else go to next phase  // after fortification it mean turn has ended


}

void Fortification::fortificationStart(Player& player)
{
	string countryToFortify, countryFortifyFrom;
	Country *fortifyThisCountry;

	cout << "----------------- Fortification Phase Start  -----------------" << endl;

	
	do
	{
		cout << "Which country to fortify? " << endl;
		// function print list of countries
		vector<Country> listCountries = currentMap->getCountryList(player.getName());

		do
		{
			cout << "Current list of all country owned by :" << player.getName() << endl;
			cout << "{write the country's name to select it}" << endl;

			for (Country country : listCountries)
			{
				cout << country.getName() << " army power:" << country.getArmy() << endl;
			}
			cin >> countryToFortify;
		} while (currentMap->get(countryToFortify) == NULL); // incorrect name 


		fortifyThisCountry = currentMap->get(countryToFortify);
		
	} while (!isFortifyPossible(*fortifyThisCountry));  //if possible then exit loop else repeat
	

	do{
		//print list of possible country that we can fortify from 
		cout << "From which country do you want to fortify? Only the countries with more 1 army are listed { select one country}" << endl;
		vector<Country> countryListfrom = currentMap->getAdjacentCountries(countryToFortify,"inc");// inc = only player countrys
		//show only the one that have more than 1 army
		for (Country country : countryListfrom)
		{
			if (country.getArmy() > 1)
			{
				cout << country.getName() << "- army power : " << country.getArmy() << endl;
			}
		}
		cin >> countryFortifyFrom;
	} while (currentMap->get(countryToFortify) == NULL);
	

	// will take army from this country
	Country *from = currentMap->get(countryFortifyFrom);


	fortify(*from, *fortifyThisCountry);

}

//function that check if adjacent allied countries have more than 1 soldier 
bool Fortification::isFortifyPossible(Country &selectedCountry)
{
	bool possible = false;

	//getlistof adjacent country
	vector<Country> countryList = currentMap->getAdjacentCountries(selectedCountry.getName(), "inc"); // only player country
	for (Country country : countryList)
	{
		// at least one country must have more than 1 army
		if (country.getArmy() > 1)
		{
			possible = true;
		}
	}

	return possible;
}


void Fortification::fortify(Country& from, Country& to)
{
	int transferFromArmy = transfert(from);
	from.setArmy(from.getArmy() - transferFromArmy);
	to.setArmy(to.getArmy() + transferFromArmy);
}

int Fortification::transfert(Country &from)
{
	int availaibleArmy = from.getArmy() - 1;  // must leave at least 1 army in the country
	int armyMoved;
	do{
		cout << "Number of availaible army : " << availaibleArmy << endl;
		cout << "How many army do wish to transfert ?  " << endl;
		cin >> armyMoved;
	} while (armyMoved > availaibleArmy || armyMoved < availaibleArmy);

	return armyMoved;
}
