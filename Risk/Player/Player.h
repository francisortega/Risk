/**
*
* @author  Francis Ortega 1295578
* @author  Michal Wozniak 1941097
* @author  Darren Mau 6057993
* @author  Francis Cote-Tremblay 6615287
*/
#include <iostream>
#include "../Map/Country.h"
#include "../Cards/Cards.h"
using namespace std;
#ifndef PLAYER_H
#define	PLAYER_H

class Player {
public:
	Player();
	Player(string name, int id);
	virtual ~Player();
	string getName();
	void setName(string name);
	Cards playerCard;
	Cards* getCards();
	void setCards(Cards* cards);
	string getComputer();
	void setComputer(string computer);
	void setId(int id);
	int getId();
private:
	string name;
	string computer;
	Cards* cards;
	Country countries[10];
	int armies;
	int id;
};

#endif	/* PLAYER_H */