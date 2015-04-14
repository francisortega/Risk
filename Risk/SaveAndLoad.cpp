/**
 *
 * @author  Francis Ortega 1295578
 * @author  Michal Wozniak 1941097
 * @author  Darren Mau 6057993
 * @author  Francis Cote-Tremblay 6615287
 */
#include "SaveAndLoad.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/**
 * The function will split the string into an array.
 */

vector<string> SaveAndLoad::split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
  
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
  
  return internal;
}

/**
 * The function will load the map and put it in contry and continent class.
 */
bool SaveAndLoad::load(Map &map,string name)
{
	int id = 0;
	try
	{
		ifstream file(name);
		file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
		string str;
		bool isContinent = false;
		bool isTerritorie = false;
		vector<string> territories;
		vector<string> name;
		vector<vector<string>> adjCountries;
		vector<string> continent;
		if (!file) {
			return false;
		}   
		while (getline(file, str))
		{
		
			if(isContinent == true && str[0] != '[' && str.length() > 0)
			{
				continent = split(str, '=');
				int num;
				istringstream ( continent[1] ) >> num;
				map.addContinents(continent[0], num);
			}
		
			if(isTerritorie == true && str[0] != '[' && str.length() > 0)
			{
				territories = split(str, ',');
				vector<string> country1;
				name.push_back(territories[0]);
				for(size_t n=4; n < territories.size(); n++)
				{
					country1.push_back(territories[n]);
				}
									adjCountries.push_back(country1);
				
				int x;
				istringstream ( territories[1] ) >> x;
				int y;
				istringstream ( territories[2] ) >> y;
				map.addCountry(id, territories[0], territories[3],x,y);
				++id;
			}
			if(str[0] == '[')
			{
				if(str == "[Continents]")
				{
					isContinent = true;
					isTerritorie = false;
				}
				else if(str == "[Territories]")
				{
					isContinent = false;
					isTerritorie = true;
				}
				else
				{
					isContinent = false;
					isTerritorie = false;
				}
			}
		
			for(size_t n=0; n < adjCountries.size(); n++)
			{
				map.addAdjacency(name[n], adjCountries[n]);
			}
		}
		if(validate(map) == true)
		{
			return true;
		}
	}
	catch (std::ifstream::failure e) 
	{
		cerr << "Exception opening/reading/closing file\n";
		return false;
	}

	catch (exception& e)
	{
		cout << e.what() << '\n';
		return false;
	}
	return false;
	
}


/**
 * The function will get the number of the country.
 */
int SaveAndLoad::getPosition(vector<Country> &countries, string findCountry)
{
	for(size_t n=0; n < countries.size(); n++)
	{
		if(countries[n].getName() == findCountry)
		{
			return n;
		}
	}
	return -1;
}

/*
 *The function will try and visit all the country and set visited to true and if the continent is visited 
 * change the visitedContinent to "".
 */

void SaveAndLoad::visitCountry(Map &map, vector<bool> &visited, vector<Country> &countries, string countryName)
{
	//get the number of the country.
	int num = getPosition(countries, countryName);
	//check if the country is visited
	if(visited[num] == false)
	{
		visited[num] = true;
		//go throught all the country that is connected to the country.
		vector<Country> adjCountries = map.getAdjacentCountries(countries[num].getName(), "all");
		for(size_t i=0; i < adjCountries.size(); i++)
		{
			visitCountry(map, visited, countries, adjCountries[i].getName());
		}
	}
}

/**
 * The function will validate if the country is graph connected and if the continent is subgraph connected.
 */
bool SaveAndLoad::validate(Map map)
{
	vector<bool> visited;
	//vector<string> visitedContinent;
	//set visited to false.
	vector<Country> *countries = map.getWorldMap();
	for(size_t n=0; n < countries->size(); n++)
	{
		visited.push_back(false);
	}
	
	visitCountry(map, visited, *countries, countries->at(0).getName());
	 
	//check if the country is connected graph.
	for(size_t n=0; n < visited.size(); n++)
	{
		if(visited[n] == false)
		{
			return false;
		}
		
	}

	
	//check if the country belong to one continent.
	vector<Map::Continent> continent = map.getContinents();
	vector<Country> countries1;
	int num;
	for(size_t n=0; n < continent.size(); n++)
	{
		countries1 = map.getCountriesOfContinents(continent[n].name);
		for(size_t i = 0; i < countries1.size(); i++)
		{
			num = getPosition(*countries,countries1[i].getName());
			if(visited[num] == false)
			{
				return false;
			}
			visited[num] = false;
		}
	}
	
	return true;
}

/**
 * The function will save the map.
 */
bool SaveAndLoad::save(Map map, string name)
{
	if(validate(map) == true)
	{
		ofstream myfile (name + ".map");
		if (myfile.is_open())
		{
			myfile << "[Continents]\n";
			vector<Map::Continent> continents = map.getContinents();
			for(size_t n=0; n < continents.size(); n++)
			{
				myfile << continents[n].name <<"=" <<continents[n].extra << "\n";
			}
			myfile << "\n";
			myfile << "[Territories]\n";
			vector<Country>* countries = map.getWorldMap();
			for(size_t n=0; n < countries->size(); n++)
			{
				//line break if it is a new continent
				if(n > 0 && countries->at(n-1).getContinent() != countries->at(n).getContinent())
				{
					myfile << "\n";
				}

				myfile << countries->at(n).getName() << ",";
				myfile << countries->at(n).getX() << ",";
				myfile << countries->at(n).getY() << ",";
				myfile << countries->at(n).getContinent() << ",";
				vector<Country> adjCountries = map.getAdjacentCountries(countries->at(n).getName(), "all");
				for(size_t i=0; i < adjCountries.size() -1; i++)
				{
					myfile << adjCountries[i].getName() << ",";
				}
				myfile << adjCountries[adjCountries.size() -1].getName() << "\n";
			}

			myfile.close();
			return true;
		}
		else 
		{
			cout << "Unable to open file";	
			return false;
		}
	}
	else
	{
		return false;
	}
}
