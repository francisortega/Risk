#include "Country.h"
#include <iostream>
using namespace std;


Country::Country()
{
	
};

Country::~Country()
{
};
Country::Country(string Name, string Owner, int NbOfArmy)
{
	name = Name;
	owner = Owner;
	nbOfArmy = NbOfArmy;
};
void Country::setName(string name)
{
	this->name=name;
}

string Country::getName()
{
	return name;
}
void Country::setOwner(string newOwner)
{
	owner = newOwner;
}
string Country::getOwner()
{
	return owner;
}
void Country::setArmy(int newArmy)
{
	nbOfArmy = newArmy;
}
int Country::getArmy()
{
	return nbOfArmy;
}
int Country::getId()
{
	return id;
}
void Country::setId(int id)
{
	this->id = id;
}
void Country::setX(int x)
{
	this->x=x;
}
int Country::getX()
{
	return x;
}
void Country::setY(int y)
{
	this->y=y;
}
int Country::getY()
{
	return y;
}
void Country::setContinent(string continent)
{
	this->continent=continent;
}
string Country::getContinent()
{
	return continent;
}

