/*
* File:   StatDecorator.h
* Author: ubuntu
*
* Created on February 18, 2015, 7:55 PM
*/
#include "Statistics.h"
#include <string>
#ifndef STATDECORATOR_H
#define	STATDECORATOR_H

class StatDecorator : public Statistics{
public:
	StatDecorator(Statistics *decoratedStats);
	StatDecorator(const StatDecorator& orig);
	~StatDecorator();
	string getStats(vector<Country> *world, list<string> playerNames);
	string getPercentages(vector<Country> *world, list<string> playerNames);
	string test();
	string myStats;
	void printStats();
protected:
	Statistics *decoratedStats;
	//list<Observer *> observers;
};

#endif	/* OBSERVER_H */

