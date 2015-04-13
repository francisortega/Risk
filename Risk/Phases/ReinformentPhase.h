#pragma once

#include "../Player/Player.h"
#include <string>
#include "../Map/Map.h"

class ReinforcementPhase
{
public:
	ReinforcementPhase(Map *map);
	~ReinforcementPhase();

	void reinforcementStart(Player &player);
	


private:
	Map *currentMap;

	int consumeCards(Player &player);
	void addMoreTroops(Player &player);
	int cardSelection(Cards playerCards);
	void reinforceWithNewTroop(int newArmy, Player *player);
	int bonusArmiesFromCountries(Player *player);
	int bonusArmiesFromContinents(Player *player);
};