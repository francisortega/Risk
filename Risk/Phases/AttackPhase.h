#pragma once
#include "../Player/Player.h"
#include "Battle.h"
#include "../Map/Map.h"

class AttackPhase
{

public:
	AttackPhase(Map *map);
	~AttackPhase();

	
	void attackPhaseStart(Player &player);

private:
	void attack(Player &currentP, Country &attack, Country &defend);
	void prepareAttack(Player & currentP);
	Map *currentMap;

};

