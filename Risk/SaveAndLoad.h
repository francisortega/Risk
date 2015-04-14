/**
 *
 * @author  Francis Ortega 1295578
 * @author  Michal Wozniak 1941097
 * @author  Darren Mau 6057993
 * @author  Francis Cote-Tremblay 6615287
 * @date    03-05-2015
 * @version project v1
 */
#ifndef SAVEANDLOAD_H
#define SAVEANDLOAD_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "Map/Map.h"
using namespace std;

class SaveAndLoad
{
	private:
		Map map;
		int getPosition(vector<Country> &countries, string findCountry);
		void visitCountry(Map &map, vector<bool> &visited, vector<Country> &countries, string countryName);

	public:
		bool load(Map &map, string name);
		static vector<string> split(string str, char delimiter);
		bool validate(Map map);
		bool save(Map map, string name);
};


#endif