/**
 *
 * @author  Francis Ortega 1295578
 * @author  Michal Wozniak 1941097
 * @author  Darren Mau 6057993
 * @author  Francis Cote-Tremblay 6615287
 * @date    03-05-2015
 * @version project v1
 */

#pragma once
#include "../Country.h"
#include "../Player.h"

class Battle
{
public:
	Battle();
	~Battle();
	void Battle::war(Player& player,Country& attacker, Country& defender);
	

private:
	 void sortRolls(int& firstRoll, int& secondRoll, int& thirdRoll);
	 void winner(Player& player,int DiceUsedbyAttack,Country& attacker, Country& defender);
	 void loser();
	 void status(Country& attacker, Country& defender);
	 int fight(Country& attacker, Country& defender);
	 void blitz(Player& player, Country& attacker, Country& defender);
	 void skirmish(Player& player, Country& attacker, Country& defender);
};