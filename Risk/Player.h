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
using namespace std;
#ifndef PLAYER_H
#define	PLAYER_H

class Player {
public:
	string name;
	Country countries[10];
	int armies;
	Player();
	Player(const Player& orig);
	virtual ~Player();
private:

};

#endif	/* PLAYER_H */

