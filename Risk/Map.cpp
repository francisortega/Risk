/**
 *
 * @author  Francis Ortega 1295578
 * @author  Michal Wozniak 1941097
 * @author  Darren Mau 6057993
 * @author  Francis Cote-Tremblay 6615287
 * @date    03-05-2015
 * @version project v1
 */

#include "Map.h"
#include <string>
#include <vector>
#include <stdio.h>

/**
 * Map
 *   
 * Class constructor - adds all the countries including their adjacency
 */
Map::Map() {
}

Map::~Map() {
}

/**
 * areContinentsAdjacent
 *
 * Determine whether two continents are adjacent
 *
 * @param continentX - string name of first continent
 * @param continentY - string name of second continent
 * @return boolean
 */
bool Map::areContinentsAdjacent(std::string continentX, std::string continentY) {
	// Get all countries within continent
	std::vector<Country> countriesCont = getCountriesOfContinents(continentX);
	bool isFound = false;

	// Check each country within continent
	for (int i = 0; i < countriesCont.size(); i++) {
		std::vector<Country> adjCountries = getAdjacentCountries(countriesCont[i].getName());
		//std::cout << "\n" << countriesCont[i].name << ":" << std::endl;

		// Loop through adjacent continents and find whether it is connected to a country from continentY
		for (int j = 0; j < adjCountries.size(); j++) {
			//std::cout << "\t" << adjCountries[j].id << adjCountries[j].name << " " << adjCountries[j].continent;

			// Only return true if country is connected to another country which is from continentY
			if (adjCountries[j].getContinent().compare(continentY) == 0) {
				isFound = true;
				break;
			}
		}

		if (isFound) break;
	}

	return isFound;
}

/**
 * getAdjacentCountries
 *
 * Retrieve all adjacent countries
 * 
 * @param countryName - string name of country
 * @return vector<struct>
 */
std::vector<Country> Map::getAdjacentCountries(std::string countryName) {
	int idc = getIdOfCountry(countryName);
	std::vector<Country> adjCountries;

	// Look in the adjacency matrix for the adjacent countries
	for (int i = 0; i < countries.size(); i++) {
		if (adjacentCountries[idc][i] == 1) {
			adjCountries.push_back(countries[i]);
		}
	}

	return adjCountries;
}

/**
 * getCountriesOfContinents
 *
 * Retrieve all countries in a continent
 *
 * @param continentName - string name of continent
 * @return vector<struct>
 */
std::vector<Country> Map::getCountriesOfContinents(std::string continentName) {
	std::vector<Country> countriesOfContinents;

	// Look for all the countries in the continent
	for (int i = 0; i < countries.size(); i++) {
		if (countries[i].getContinent().compare(continentName) == 0) {
			countriesOfContinents.push_back(countries[i]);
		}
	}

	return countriesOfContinents;
}

/**
 * getWorldMap
 *
 * Retrieve all countries in the world
 *
 * @return vector<struct>
 */
std::vector<Country> *Map::getWorldMap() {
	return &countries;
}

/**
 * get
 *
 * Retrieve all information of a country
 *
 * @param countryX - string name of first country
 * @return struct
 */
Country *Map::get(std::string countryName) {

	// Look for the country with that name
	for (int i = 0; i < countries.size(); i++) {
		if (countries[i].getName().compare(countryName.c_str()) == 0) {
			return &countries[i];
		}
	}
	return NULL;
}

/**
 * isAdjacent
 *
 * Check whether two countries are adjacent
 *
 * @param countryX - string name of first country
 * @param countryY - string name of second country
 * @return boolean
 */
bool Map::isAdjacent(std::string countryX, std::string countryY) {
	// Get id of both countries
	int countryIdX = getIdOfCountry(countryX);
	int countryIdY = getIdOfCountry(countryY);

	return (adjacentCountries[countryIdX][countryIdY] == 1 || adjacentCountries[countryIdY][countryIdX] == 1) ? true : false;
}

/**
 * addCountry
 *
 * Add country to the world map
 *
 * @param id - index of country in the vector
 * @param countryName - string name of country
 * @param continentName - string name of continent
 * @return void
 */
void Map::addCountry(int id, std::string countryName, std::string continentName, int x, int y) {

	// Add country information
	countryInfo.setId(id); // index in the vector array
	countryInfo.setName(countryName);
	countryInfo.setContinent(continentName);
	countryInfo.setX(x);
	countryInfo.setY(y);


	// Add to list of countries
	countries.push_back(countryInfo);
}

/**
 * addAdjacency
 *
 * Add connection between two countries
 *
 * @param countryX - string name of country
 * @param adjCountries - array string of adjacent countries
 * @return void
 */
void Map::addAdjacency(std::string countryX, std::vector<std::string> adjCountries) {
	// ID of country
	int countryIdX = getIdOfCountry(countryX);

	for (int i = 0; i < adjCountries.size(); i++) {
		// Get ID's of adjacent countries
		int countryIdY = getIdOfCountry(adjCountries[i]);

		// Identity matrix
		adjacentCountries[countryIdX][countryIdY] = 1;
		adjacentCountries[countryIdY][countryIdX] = 1;
	}
}

/**
 * addPlayerToCountry
 *
 * Include a player to a country
 *
 * @param countryName - string name of country
 * @param playerName - string name of player
 * @return void
 */
void Map::addPlayerToCountry(std::string countryName, std::string playerName) {
	// Loop entire country list to find for the id
	for (int i = 0; i < countries.size(); i++) {
		if (countries[i].getName().compare(countryName.c_str()) == 0) {
			countries[i].getOwner() = playerName;
		}
	}
}

/**
 * getIdOfCountry
 *
 * Retrieve id of a country
 *
 * @param countryName - string name of country
 * @return int
 */
int Map::getIdOfCountry(std::string countryName) {
	int idc = 0;

	// Loop entire country list to find for the id
	for (int i = 0; i < countries.size(); i++) {
		if (countries[i].getName().compare(countryName.c_str()) == 0) {
			idc = countries[i].getId();
		}
	}

	return idc;
}

/**
 * createVector
 *
 * Because the labs are using visual studio 2012 (I use 2013), my code gets a bunch of errors due to compiler incompatibility
 * Please upgrade the Vstudios in the lab. I wasted my time.
 *
 * @param countries - array of strings of countries
 * @return vector<string>
 */
std::vector<std::string> Map::createVector(std::string countryNames[], int length) {
	std::vector<std::string> countryList;
	
	/* sizeof(array)/sizeof(array[0]) didn't work so I used length */
	for(int i = 0; i < length; i++) {
		countryList.push_back(countryNames[i]);
	}

	return countryList;
}

/**
 * getContinents
 *
 * Retrieve continenets
 *
 * @return vector<string>
 */
std::vector<Map::Continent> Map::getContinents()
{
	return continents;
}

void Map::addContinents(std::string c, int num)
{
	continentInfo.name = c;
	continentInfo.extra = num;
	continents.push_back(continentInfo);
}
