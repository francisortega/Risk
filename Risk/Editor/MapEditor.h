#pragma once

#include <iostream>
#include <string>
#include "../SaveAndLoad.h"
using namespace std;

class MapEditor
{
	private:
		void createContinent(Map &map);
		void createCountry(Map &map);
		void createAdjacent(Map &map);
		int checkInt(int size);
		string answer(string name);
	public:
		bool createMap(Map &map, string choose, string name);
};

