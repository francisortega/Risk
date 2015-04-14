/* 
 * File:   Statistics.cpp
 * Author: ubuntu
 * 
 * Created on February 18, 2015, 7:50 PM
 */

//Statistics class is the observable class

#include "Statistics.h"

#include <list>
#include <string>
#include <map>
#include <iostream>

using namespace std;

Statistics::Statistics() {
}

Statistics::Statistics(const Statistics& orig) {
}

Statistics::~Statistics() {
    
}

string Statistics::test(){
	return " statistics";
}
string Statistics::getStats(vector<Country> *world, list<string> playerNames) {
	return "The statistics are: ";
}
string Statistics::getPercentages(vector<Country> *world, list<string> playerNames){
	return "The percentages are: ";
}






