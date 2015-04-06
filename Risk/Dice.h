#pragma once
class Dice
{
public:
	Dice();
	~Dice();
	static int Dice::roll();
	static void Dice::sort(int& firstRoll, int& secondRoll);
	static void Dice::sort(int& firstRoll, int& secondRoll, int& thirdRoll);
	
};

