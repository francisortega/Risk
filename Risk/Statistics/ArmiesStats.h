
#include "StatDecorator.h"
#include "Statistics.h"
#include <string>
#ifndef ARMIESSTATS_H
#define	ARMIESTSTATS_H

class ArmiesStats : public StatDecorator{
public:
	ArmiesStats(Statistics *decoratedStats) : StatDecorator(decoratedStats){};
	ArmiesStats(const ArmiesStats& orig);
	~ArmiesStats();
	string getStats(vector<Country> *world, list<string> playerNames);
	string test();
	void printStats();
	string myStats;
	
};

#endif	

