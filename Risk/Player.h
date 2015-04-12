/**
 *
 * @author  Francis Ortega 1295578
 * @author  Michal Wozniak 1941097
 * @author  Darren Mau 6057993
 * @author  Francis Cote-Tremblay 6615287
 * @date    03-05-2015
 * @version project v1
 */
#include <iostream>
#include "Country.h"
#include "Cards\Cards.h"
using namespace std;
#ifndef PLAYER_H
#define	PLAYER_H

class Player {
public:
	Player(string name);
	virtual ~Player();
	string getName();
	void setName(string name);
	Cards playerCard;
private:
	string name;
	Country countries[10];
	int armies;	
};

#endif	/* PLAYER_H */

