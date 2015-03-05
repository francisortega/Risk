#ifndef SAVEANDLOAD_H
#define SAVEANDLOAD_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "Map.h"
using namespace std;

class SaveAndLoad
{
	private:
		Map map;

	public:
		bool load(Map &map, string name);
		vector<string> split(string str, char delimiter);
		bool validate(Map map);
		void visitCountry(Map &map, vector<bool> &visited, vector<Country> &countries, string countryName);
		int getNumber(vector<Country> &countries, string findCountry);
		bool save(Map map, string name);
};


#endif