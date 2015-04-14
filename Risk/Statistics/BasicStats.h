
#ifndef BASICSTATS_H
#define	BASICSTATS_H

#include "Statistics.h"

#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;


#include "Observable.h"

class BasicStats : public Statistics{
public:

	BasicStats();
	virtual ~BasicStats();
	string getStats(vector<Country> *world, list<string> playerNames);
	string getPercentages(vector<Country> *world, list<string> playerNames);
	string test();
	string myStats;
	void printStats();
	BasicStats(const BasicStats& orig);
	//list<Observer *> observers;
};

#endif	/* DECORATOR_H */

