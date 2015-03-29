#include "Dice.h"
#include <time.h>
#include <stack>
using namespace std;

Dice::Dice()
{
}


Dice::~Dice()
{
}

/**
*   Roll a random integer
*
*	@return int roll
*/
int Dice::roll()
{
	int roll;
	roll = (1 + rand() % 6);
	return roll;
}
/**
*	sort the rolls from biggest to smallest
*	@param int& firstRoll, secondRoll
*/
void Dice::sort(int& firstRoll, int& secondRoll)
{
	if (secondRoll > firstRoll)
		swap(secondRoll, firstRoll);
}
/**
*	sort the rolls from biggest to smallest
*	@param int& firstRoll, secondRoll, thirdRoll
*/
void Dice::sort(int& firstRoll, int& secondRoll, int& thirdRoll)
{
	if (thirdRoll > secondRoll)
		swap(thirdRoll, secondRoll);
	if (thirdRoll > firstRoll)
		swap(thirdRoll, firstRoll);
	if (secondRoll > firstRoll)
		swap(secondRoll, firstRoll);
}