#pragma once
#include "Country.h"

class Battle
{
public:
	Battle();
	~Battle();
	void Battle::war(Country& attacker, Country& defender);
	

private:
	int rollDice();
	void sortRolls(int& firstRoll, int& secondRoll);
	void sortRolls(int& firstRoll, int& secondRoll, int& thirdRoll);
	void winner(int DiceUsedbyAttack,Country& attacker, Country& defender);
	void loser();
	void status(Country& attacker, Country& defender);
	int fight(Country& attacker, Country& defender);
	void blitz(Country& attacker, Country& defender);
	void skirmish(Country& attacker, Country& defender);
};