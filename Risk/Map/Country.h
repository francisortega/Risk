/**
 *
 * @author  Francis Ortega 1295578
 * @author  Michal Wozniak 1941097
 * @author  Darren Mau 6057993
 * @author  Francis Cote-Tremblay 6615287
 */
#pragma once
#include <iostream>
using namespace std;
class Country
{
public:
	Country();
	~Country();
	Country(string name, string owner, int nbOfArmy);
	
	int getId();
	void setId(int id);

	string getName();
	void setName(string name);

	void setOwner(string newOwner);
	string getOwner();
	

	int getArmy();
	void setArmy(int newArmy);

	string getContinent();
	void setContinent(string continent);
	
	int getX();
	void setX(int x);

	int getY();
	void setY(int y);


private:
	string name;
	string owner;
	int nbOfArmy;
	int id;
	int x;
	int y;
	string continent;

};