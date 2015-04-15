/**
*
* @author  Francis Ortega 1295578
* @author  Michal Wozniak 1941097
* @author  Darren Mau 6057993
* @author  Francis Cote-Tremblay 6615287
*/
#include "Player.h"

Player::Player()
{
	this->cards = new Cards();
}

Player::Player(string name, int id)
{
	this->name = name;
	this->id = id;
	this->cards = new Cards();
}


Player::~Player()
{
}

void Player::setName(string name){
	this->name = name;
}

string Player::getName(){
	return this->name;
}

Cards* Player:: getCards()
{
	return cards;
}

void Player::setCards(Cards* cards)
{
	this->cards = cards;
}
string Player::getComputer()
{
	return computer;
}

void Player::setComputer(string computer)
{
	this->computer = computer;
}

void Player::setId(int id)
{
	this->id = id;
}
int Player::getId()
{
	return id;
}