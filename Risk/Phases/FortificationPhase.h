#pragma once
#include "../Player/Player.h"
#include <string>
#include "../Map/Map.h"

class Fortification
{
public:
	Fortification(Map *map);
	~Fortification();

	void fortificationSetup(Player& player);
	void fortificationStart(Player& player);
	bool isFortifyPossible(Country& selectedCountry);
	void fortify(Country& from, Country& to);
	int transfert(Country & from);

private:
	Map *currentMap;
};

