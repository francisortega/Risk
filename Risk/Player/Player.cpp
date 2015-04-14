/**
*
* @author  Francis Ortega 1295578
* @author  Michal Wozniak 1941097
* @author  Darren Mau 6057993
* @author  Francis Cote-Tremblay 6615287
* @date    03-05-2015
* @version project v1
*/
#include "Player.h"

Player::Player()
{
	this->cards = new Cards();
}

Player::Player(string name)
{
	this->name = name;
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