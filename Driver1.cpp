/**
 *
 * @author  Francis Ortega 1295578
 * @date    02-05-2015
 * @version Assignment 1
 *
 * Driver
 *
 * Initializes the Map class and starts the map functions
 *
 */

#pragma once

#include "Map.h"
#include <vector>
#include <stdio.h>
#include <string>
#include "SaveAndLoad.h"
#include <time.h>
#include "Battle.h"

int main(int argc, char*argv[]){

	SaveAndLoad* test = new SaveAndLoad();
	Map map;
	bool t = test->load(map,"World.map");
	if(t == true)
	{
		cout<<"Work"<<endl;
	}
	else
	{
		cout<<"Didnt Work"<<endl;
	}
	cout<<"Save: ";
	if(t == true && test->save(map, "test") == true)
	{
		cout<<"Work"<<endl;
	}
	else
	{
		cout<<"Didnt Work"<<endl;
	}

	if(t == true)
	{
		/*
		// Get all countries in the world
		std::vector<Country> countries = map.getWorldMap();

		// Display all the countries
		for (int i = 0; i < countries.size(); i++) {
			printf("name: %s id: %i continent: %s\n", countries[i].getName().c_str(), countries[i].getId(), countries[i].getContinent().c_str());
		}

		// Display a continent and all its countries
		std::vector<Country> countriesByContinent = map.getCountriesOfContinents("North America");

		printf("\nCountries in the continent of %s \n", "North America");
		for (int i = 0; i < countriesByContinent.size(); i++) {
			printf("\t%i %s\n", i + 1, countriesByContinent[i].getName().c_str());
		}

		// Display if two countries are adjacent (sample)
		printf("\nAre Quebec and Greenland adjacent? ");
		std::string resultCountries1 = map.isAdjacent("Quebec", "Greenland") ? "true" : "false";
		printf("%s \n", resultCountries1.c_str());

		printf("Are Quebec and China adjacent? ");
		std::string resultCountries2 = map.isAdjacent("Quebec", "China") ? "true" : "false";
		printf("%s \n", resultCountries2.c_str());

		// Display if two countries are adjacent (sample)
		printf("\nIs North America connected to South America? ");
		std::string resultContinents1 = map.areContinentsAdjacent("North America", "South America") ? "true" : "false";
		printf("%s \n", resultContinents1.c_str());

		printf("Is North America connected to Australia? ");
		std::string resultContinents2 = map.areContinentsAdjacent("North America", "Australia") ? "true" : "false";
		printf("%s \n", resultContinents2.c_str());

		// Add a player
		map.addPlayerToCountry("Quebec", "Player1");

		// Display info of country (it belongs to only one continent)
		Country country = map.get("Quebec");
		printf("\nMore information about %s \n", "Quebec");
		printf("\t Name: %s \n\t ID: %i \n\t Continent: %s \n\t Player: %s\n ", country.getName().c_str(), country.getId(), country.getContinent().c_str(), country.getOwner().c_str());

		// Display all adjacent countries of a country
		std::vector<Country> connectedCountries = map.getAdjacentCountries("Quebec");

		printf("\nCountries connected to %s \n", "Quebec");
		for (int i = 0; i < connectedCountries.size(); i++) {
			printf("\t%i %s\n", i + 1, connectedCountries[i].getName().c_str());
		}
		*/
		/* Add armies (not sure how armies work) - not done
		addArmiesToCountry();
		*/
		//country m("canada", "RED", 10);
		//country *z = new country("canada","red", 1);
		//string a = z->getName();
		//cout << "name is" << a << endl;
	
	
		srand(static_cast<int>(time(0))); //get real random 

		/*
		Country world[5] = 
		{ 
			map.get("Quebec", "red", 10), 
			map.get("usa", "red", 5),
			map.get("brazil", "red", 1),
			map.get("mexico", "blue", 5),
			map.get("uk", "blue", 10)
		};*/
	
		//c->setOwner("A");
		map.get("Quebec")->setArmy(10);
		map.get("Ontario")->setArmy(5);
		map.get("Quebec")->setOwner("A");
		map.get("Ontario")->setOwner("B");
		
		vector<Country> world = map.getWorldMap();
		world.size();
		world.at(0).setOwner("francis");
		cout << world.at(0).getOwner();

		int limit = world.size();
			for (int i=0; i<limit; ++i)
			{
				
				cout << i << world[i].getName() << endl;
				
				
			}
		
		//map.get("Quebec")->setOwner("A");
		//map.get("Ontario")->setOwner("B");

		Battle risk;
		risk.war(*map.get("Quebec"),*map.get("Ontario"));
	}
	
	delete test;
	system("pause");
}
