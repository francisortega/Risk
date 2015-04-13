/**
 *
 * @author  Francis Ortega 1295578
 * @author  Michal Wozniak 1941097
 * @author  Darren Mau 6057993
 * @author  Francis Cote-Tremblay 6615287
 */
#include "Battle.h"
#include <stdlib.h>
#include <time.h>
#include "../Map/Country.h"
#include <stack>
#include <string>
#include "Dice.h"

Battle::Battle()
{
}


Battle::~Battle()
{
}

/**
*	One country attack another one,
*	@param Country& attacker, defender	reference to the attacking and defending country
*	@return attackerDices Number of dice used by the attacker during the fight
*/
int Battle::fight(Country& attacker, Country& defender)
{

	//dice rolls
	int attackRoll1=0, attackRoll2=0, attackRoll3=0;
	int defenceRoll1=0, defenceRoll2=0;

	//numbers of dices
	int attackerDices = 0, defenderDices = 0;
	cout << attacker.getArmy() << endl;
	cout << defender.getArmy() << endl;
	//attack roll
	if (attacker.getArmy() >= 3)
	{

		attackRoll1 = Dice::roll();
		attackRoll2 = Dice::roll();
		attackRoll3 = Dice::roll();
		attackerDices = 3;
	}
	else if (attacker.getArmy() == 2)
	{
		attackRoll1 = Dice::roll();
		attackRoll2 = Dice::roll();
		attackRoll3 = 0;// will be ignored
		attackerDices = 2;
	}
	else if (attacker.getArmy() == 1)
	{
		attackRoll1 = Dice::roll();
		attackRoll2 = 0;
		attackRoll3 = 0;
		attackerDices = 1;
	}
	if (defender.getArmy() >= 2)
	{
		defenceRoll1 = Dice::roll();
		defenceRoll2 = Dice::roll();
		defenderDices = 2;
	}
	else if (defender.getArmy() == 1)
	{
		defenceRoll1 = Dice::roll();
		defenceRoll2 = 0;
		defenderDices = 1;
	}

	//sort all the rolls, high to low
	Dice::sort(attackRoll1, attackRoll2, attackRoll3);
	Dice::sort(defenceRoll1, defenceRoll2);


	//Display rolls
	cout << endl << "Attacker has rolled: " << attackRoll1 << "  ";
	if (attackRoll2 != 0)
		cout << attackRoll2 << "  ";
	if (attackRoll3 != 0)
		cout << attackRoll3 << "  ";
	cout << endl << "Defender has rolled: " << defenceRoll1 << "  ";
	if (defenceRoll2 != 0)
		cout << defenceRoll2 << endl;

	//Battle --------------------------------------
	//Compare attack vs defense
	if (attackRoll1 <= defenceRoll1)
	{
		attacker.setArmy(attacker.getArmy() - 1);
	}
	if (attackRoll1 > defenceRoll1)
	{
		defender.setArmy(defender.getArmy() - 1);
	}

	// both still have army remaining  
	if (attacker.getArmy() > 1 && defender.getArmy() > 0 || defenderDices == 2)
	{
		//defence has 2 dice so fight continue 
		if (attackRoll2 == defenceRoll2)
		{
			attacker.setArmy(attacker.getArmy() - 1);
		}
		if (attackRoll2 > defenceRoll2)
		{
			defender.setArmy(defender.getArmy() - 1);
		}
		if (attackRoll2 < defenceRoll2)
		{
			attacker.setArmy(attacker.getArmy() - 1);
		}

	}
	// if  win => we need to know how many dice we used during fight
	return attackerDices;
}


void Battle::loser()
{
	cout << "you have only one army left, you can't attack anymore!!! the invasion is over";
}

/**
*	Attacking country has won, system must update the values of both country
*	@param int DiceUsedbyAttack  Number of dice used during the attack
*   @param Country& attacker, defender	reference to the attacking and defending country
*/
void Battle::winner(Player& player, int DiceUsedbyAttack, Country& attacker, Country& defender){

	defender.setOwner(attacker.getOwner());
	cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!---WINNER ---!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	cout << "\nAttacker has won, he is the new owner of " << defender.getName() << endl;

	int moveArmy;
	//how much soldier you will move to the new Country
	cout << "you have " << attacker.getArmy() << " remaining in your winner Country " << endl;
	cout << "how many army do you wish to move to your new Country ? ";
	cin >> moveArmy;

	// Conditions to how many army the winning country can send to her new country
	while (moveArmy < DiceUsedbyAttack || moveArmy >= attacker.getArmy())
	{
		if (attacker.getArmy() == DiceUsedbyAttack && moveArmy < attacker.getArmy())
		{
			//moveArmy is =1 , dice used is 2 
			//user can only send 1 unit because he need to keep at least one in the attacker Country 
			break;
		}
		if (moveArmy == attacker.getArmy())
		{
			cout << "You need to at least leave one army in the attacker Country" << endl;
			cout << "how many army do you wish to move to your new Country ?" << endl;
		}
		else
		{
			cout << " place a number of armies in the conquered Country which is greater or equal than the number of dice that was used";

		}
		cin >> moveArmy;

	}
	//update 
	attacker.setArmy(attacker.getArmy() - moveArmy);
	defender.setArmy(moveArmy);

	//Winning a card
	if (!player.playerCard.hasAlreadyCaptureOneCountry)
	{
		player.playerCard.add();
		player.playerCard.setCaptureOneCountry();
	}



}
void Battle::status(Country& attacker, Country& defender)
{
	cout << "Attacker has " << attacker.getArmy() << " armies left" << endl;
	cout << "Defender has " << defender.getArmy() << " armies left" << endl;
}
/**
*	All in attack mode, attack until attacking army has only 1 army left or has won
*   @param Country& attacker, defender	reference to the attacking and defending country
*/
void Battle::blitz(Player& player, Country& attacker, Country& defender)
{
	//fight 
	while (attacker.getArmy() > 1 && defender.getArmy() > 0)
	{
		int DiceUsedbyAttack = fight(attacker, defender);
		status(attacker, defender);

		if (attacker.getArmy() == 1)
		{
			loser();
			break;
		}
		if (defender.getArmy() == 0)
		{
			//attacker won
			winner(player, DiceUsedbyAttack, attacker, defender);
			break;
		}

	}
}
/**
*	skirmish : one single fight
*   @param Country& attacker, defender	reference to the attacking and defending country
*/
void Battle::skirmish(Player& player, Country& attacker, Country& defender)
{

	int choice;
	do
	{
		int DiceUsedbyAttack = fight(attacker, defender);
		//RESULT
		if (defender.getArmy() == 0)
		{
			//attacker won
			winner(player, DiceUsedbyAttack, attacker, defender);
			break; //stop skrmish 
		}
		else
		{
			status(attacker, defender);
			if (attacker.getArmy() == 1)
			{
				loser();
				break; // stop skirmish
			}
			cout << "Do you which to continue the fight or stop ---  (continue = 1, stop = 2)";
			cin >> choice;


		}
	} while (choice != 2);

}

/**
*	Show all the valid action available during the war phase
*   @param Country& attacker, defender	reference to the attacking and defending country
*/
void Battle::war(Player& player, Country& attacker, Country& defender)
{
	int choice;
	do{
		cout << "\n-----------------------------------------------------" << endl;
		cout << "choose a war option: " << endl;
		cout << "0 --> skirmish" << endl;
		cout << "1 --> blitz (all in attack mode) " << endl;
		cout << "2---> exit" << endl;
		cout << "select ==> ";
		cin >> choice;
	} while (choice != 0 && choice != 1 && choice != 2);

	switch (choice)
	{
	case 0: skirmish(player, attacker, defender);
		break;
	case 1: blitz(player, attacker, defender);
		break;
	case 2:
		//exit war option menu
		break;
	}
}