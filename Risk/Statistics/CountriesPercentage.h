
#include "StatDecorator.h"
#include "Statistics.h"
#include <string>
#ifndef COUNTRIESSTATS_H
#define	COUNTRIESSTATS_H

class CountriesPercentage : public StatDecorator{
public:
	CountriesPercentage(Statistics *decoratedStats) : StatDecorator(decoratedStats){};
	CountriesPercentage(const CountriesPercentage& orig);
	~CountriesPercentage();
	string getStats(vector<Country> *world, list<string> playerNames);
	string test();
	void printStats();
	string myStats;
	
};

#endif	

