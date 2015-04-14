
#include "StatDecorator.h"
#include "Statistics.h"
#include <string>
#ifndef ARMIESSTATS_H
#define	ARMIESTSTATS_H

class CountriesStats : public StatDecorator{
public:
	CountriesStats(Statistics *decoratedStats) : StatDecorator(decoratedStats){};
	CountriesStats(const CountriesStats& orig);
	~CountriesStats();
	string getStats(vector<Country> *world, list<string> playerNames);
	string test();
	void printStats();
	string myStats;
	
};

#endif	

