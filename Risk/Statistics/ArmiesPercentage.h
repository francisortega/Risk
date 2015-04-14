
#include "StatDecorator.h"
#include "Statistics.h"
#include <string>
#ifndef ARMIESPERCENTAGE_H
#define	ARMIESPERCENTAGE_H

class ArmiesPercentage : public StatDecorator{
public:
	ArmiesPercentage(Statistics *decoratedStats) : StatDecorator(decoratedStats){};
	ArmiesPercentage(const ArmiesPercentage& orig);
	~ArmiesPercentage();
	string getStats(vector<Country> *world, list<string> playerNames);
	string test();
	void printStats();
	string myStats;
	
};

#endif	

