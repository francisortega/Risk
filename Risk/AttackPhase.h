#pragma once
#include "Player.h"
#include "AttackPhase\Battle.h"
#include "Map.h"

class AttackPhase
{

public:
	AttackPhase(Map map);
	~AttackPhase();

	
	void attackPhaseStart(Player &player);

private:
	void attack(Player &currentP, Country &attack, Country &defend);
	void prepareAttack(Player & currentP);
	Map currentMap;

};

