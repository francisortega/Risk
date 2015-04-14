/*
* File:   StatDecorator.cpp
* Author: ubuntu
*
* Created on February 18, 2015, 7:50 PM
*/

//StatDecorator class is the observable class

#include "StatDecorator.h"

#include <list>
#include <string>
#include <iostream>
using namespace std;

StatDecorator::StatDecorator(Statistics *decoratedStats) {
	this->decoratedStats = decoratedStats;
	//this->observers = decoratedStats->getObservers();
}

StatDecorator::StatDecorator(const StatDecorator& orig) {
}

StatDecorator::~StatDecorator(){}

void StatDecorator::printStats(){
	cout << this->myStats << endl;
}

string StatDecorator::test(){
	return decoratedStats->test();
}

string StatDecorator::getStats(vector<Country> *world, list<string> playerNames) {
	return decoratedStats->getStats(world, playerNames);
}
string StatDecorator::getPercentages(vector<Country> *world, list<string> playerNames){
	return decoratedStats->getPercentages(world, playerNames);
}








