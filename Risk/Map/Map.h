/**
*
* @author  Francis Ortega 1295578
* @author  Michal Wozniak 1941097
* @author  Darren Mau 6057993
* @author  Francis Cote-Tremblay 6615287
*
* Map Class
*
* Defines the structure of the world map, implementing a connected graph where nodes are
* countries connected by edges which is defined by a matrix.
*
*/

#pragma once

#include "Country.h"
#include <vector>
#include <string>
#include <iostream>

const int MAX_COUNTRIES_NUM = 42;

class Map
{
public:
	Map();
	~Map();

	Country countryInfo;

	struct Continent {
		std::string name;
		int extra;
	} continentInfo;

	/* Methods to retrieve more about the world map */
	std::vector<Country> getCountriesOfContinents(std::string continentName);
	std::vector<Country> *getWorldMap();
	std::vector<Country> getAdjacentCountries(std::string countryName, std::string countryType);

	/* Get countries and adjacent countries by a player */
	std::vector<Country> getCountryList(std::string playerName);

	/* Get more information about a country */
	Country *get(std::string countryName);

	/* Two countries adjacent */
	bool isAdjacent(std::string countryX, std::string countryY);

	/* Two continents adjacent */
	bool areContinentsAdjacent(std::string continentX, std::string continentY);

	/* Add country to worldmap */
	void addCountry(int id, std::string countryName, std::string continentName, int x, int y);

	/* Add adjacency between two countries */
	void addAdjacency(std::string countryX, std::vector<std::string> adjCountries);

	/* Get id of a country */
	int getIdOfCountry(std::string countryName);

	/* Assign player to country */
	void addPlayerToCountry(std::string countryName, std::string playerName);

	/* Assign armies to country */
	void addArmiesToCountry(std::string countryName, std::string armies);

	/* Create a vector */
	std::vector<std::string> Map::createVector(std::string countryNames[], int length);

	/* Get the continents */
	std::vector<Continent> Map::getContinents();

	/* Add continents */
	void addContinents(std::string c, int num);

protected:
	/* Matrix to hold each country's adjacency */
	int adjacentCountries[MAX_COUNTRIES_NUM][MAX_COUNTRIES_NUM];

	/* List of countries */
	std::vector<Country> countries;

	/* List of continents */
	std::vector<Continent> continents;
};