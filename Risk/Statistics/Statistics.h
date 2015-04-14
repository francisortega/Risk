
#ifndef STATISTICS_H
#define	STATISTICS_H

#include "..\Map\Country.h"

#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;


#include "Observable.h"

class Statistics : public Observable{
public:
    Statistics();
    virtual ~Statistics();
	virtual string getStats(vector<Country> *world, list<string> playerNames) = 0;
	virtual string getPercentages(vector<Country> *world, list<string> playerNames) = 0;
	virtual string test() = 0;
	virtual void printStats() = 0;
	//string myStats;
protected:
	Statistics(const Statistics& orig);
	
	//list<Observer *> observers;
};

#endif	/* DECORATOR_H */

