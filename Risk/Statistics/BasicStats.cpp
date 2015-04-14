
#include "BasicStats.h"

#include <list>
#include <string>
#include <map>
#include <iostream>

using namespace std;

BasicStats::BasicStats() {
}

BasicStats::BasicStats(const BasicStats& orig) {
}

BasicStats::~BasicStats() {

}
void BasicStats::printStats(){
	cout << this->myStats << endl;
}

string BasicStats::test(){
	return " basicStats";
}
string BasicStats::getStats(vector<Country> *world, list<string> playerNames) {
	this->myStats = "The statistics are: \n";
	return "The statistics are: \n";
}
string BasicStats::getPercentages(vector<Country> *world, list<string> playerNames){
	this->myStats = "The percentages are: \n";
	return "The percentages are: \n:";
}






