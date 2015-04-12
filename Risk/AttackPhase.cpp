#include "AttackPhase.h"
#include <string>
#include "Map.h"
using namespace std;

AttackPhase::AttackPhase(Map map)
{
	this->currentMap = map;
}


AttackPhase::~AttackPhase()
{
}

/*
	After placing your armies at the beginning of your turn, decide if you wish
	to attack at this time. 
*/
void AttackPhase::attackPhaseStart(Player  &player)
{
	int answer;
	cout << "----------------- Attack Phase Start for " << player.getName() << " -----------------" << endl;
	do{
		cout << "Do you want to attack? { 0 = YES;  1 = NO }";
		cin >> answer;
	} while (answer != 0 || answer != 1);
	while (answer == 0)
	{
		prepareAttack(player);
		cout << "Do you want to attack again? { 0 = YES;  1 = NO }";
		cin >> answer;
	}
}

/*
	-Show a list of countries user can attack with 
	-After user select a country, show a list of potential adjacent country that can be attacked
	- Start battle 
*/
void AttackPhase::prepareAttack(Player &currentP)
{
	string selectedCountry, enemy;
	vector<Country> adjacentCountries;
	do{
		//show list of owned country that can attack 
		vector<Country> ownedCountryList = currentMap.getCountryList(currentP.getName());
		cout << "Choose a country you wish to use for an attack {write country name}" << endl;
		for (Country country : ownedCountryList)
		{
			cout << country.getName() <<" - army power : " << country.getArmy() << endl;
		}
		cin >> selectedCountry; //selected country name
		//show list of ennemi adjacent country
		adjacentCountries = currentMap.getAdjacentCountries(selectedCountry, "exc"); // exc = only ennemy
	} while (currentMap.get(selectedCountry) == NULL); // country name incorrect therefore does not exist

	do{
		cout << "Which adjacent country do you wish to attack {write enemy country name}" << endl;
		for (Country countryEnemy : adjacentCountries)
		{
			cout << countryEnemy.getName() << "- army power : " << countryEnemy.getArmy() << endl;
		}
		cin >> enemy; //name of country
	} while (currentMap.get(enemy) == NULL);// country name incorrect therefore does not exist
	
	
	//get pointer of each country 
	Country *countryAttacking = currentMap.get(selectedCountry);
	Country *CountryEnemy = currentMap.get(enemy);

	Battle battle;
	battle.war(currentP, *countryAttacking, *CountryEnemy);

}