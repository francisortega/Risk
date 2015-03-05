/**
 *
 * @author  Francis Ortega 1295578
 * @author  Michal Wozniak 1941097
 * @author  Darren Mau 6057993
 * @author  Francis Cote-Tremblay 6615287
 * @date    03-05-2015
 * @version project v1
 */
#include "Battle.h"
#include <stdlib.h>
#include <time.h>
#include "Country.h"
#include <stack>
#include <string>

Battle::Battle()
{
}


Battle::~Battle()
{
}
/**
*   Roll a random integer 
*
*	@return int roll 
*/
int Battle::rollDice()
{
	//srand(static_cast<int>(time(0))); in mAIN TO BE RANDOM
	int roll;
	roll = (1 + rand() % 6);
	return roll;
}
/**
*	sort the rolls from biggest to smallest
*	@param int& firstRoll, secondRoll  
*/
void Battle::sortRolls(int& firstRoll, int& secondRoll)
{
	if (secondRoll > firstRoll)
		swap(secondRoll, firstRoll);
	//firstroll is higher roll 
}
/**
*	sort the rolls from biggest to smallest
*	@param int& firstRoll, secondRoll, thirdRoll  
*/
void Battle::sortRolls(int& firstRoll, int& secondRoll, int& thirdRoll)
{
	if (thirdRoll > secondRoll)
		swap(thirdRoll, secondRoll);
	if (thirdRoll > firstRoll)
		swap(thirdRoll, firstRoll);
	if (secondRoll> firstRoll)
		swap(secondRoll, firstRoll);
	//firstroll is higher roll 
}
/**
*	One country attack another one, 
*	@param Country& attacker, defender	reference to the attacking and defending country  
*	@return attackerDices Number of dice used by the attacker during the fight
*/
int Battle::fight(Country& attacker, Country& defender)
{

		//dice rolls
		int attackRoll1 , attackRoll2, attackRoll3;
		int defenceRoll1, defenceRoll2;

		//numbers of dices
		int attackerDices = 0, defenderDices;
		cout << attacker.getArmy() << endl;
		cout << defender.getArmy() << endl;
		//attack roll
		if (attacker.getArmy() >= 3)
		{
			attackRoll1 = rollDice();
			attackRoll2 = rollDice();
			attackRoll3 = rollDice();
			attackerDices = 3;
		}
		else if (attacker.getArmy() == 2)
		{
			attackRoll1 = rollDice();
			attackRoll2 = rollDice();
			attackRoll3 = 0;// will be ignored
			attackerDices = 2;
		}
		else if (attacker.getArmy() == 1)
		{
			attackRoll1 = rollDice();
			attackRoll2 = 0;
			attackRoll3 = 0;
			attackerDices = 1;
		}
		if (defender.getArmy() >= 2)
		{
			defenceRoll1 = rollDice();
			defenceRoll2 = rollDice();
			defenderDices = 2;
		}
		else if (defender.getArmy() == 1)
		{
			defenceRoll1 = rollDice();
			defenceRoll2 = 0;
			defenderDices = 1;
		}

		//sort all the rolls, high to low
		sortRolls(attackRoll1, attackRoll2, attackRoll3);
		sortRolls(defenceRoll1, defenceRoll2);

		//Display rolls
		cout << endl << "Attacker has rolled: " << attackRoll1 << "  ";
		if (attackRoll2 != 0)
			cout << attackRoll2 << "  ";
		if(attackRoll3!=0)
			cout << attackRoll3 << "  ";
		cout << endl << "Defender has rolled: " << defenceRoll1 << "  ";
		if(defenceRoll2 !=0)
			cout << defenceRoll2 << endl;

		//Battle --------------------------------------
		//Compare attack vs defense
		if (attackRoll1 == defenceRoll1)
		{
			int newArmy = attacker.getArmy() - 1;
			attacker.setArmy(newArmy);
		}
		else
		{
			if (attackRoll1 > defenceRoll1)
			{
				defender.setArmy(defender.getArmy() - 1);
			}
			else if (attackRoll1 < defenceRoll1)
			{
				attacker.setArmy(attacker.getArmy() - 1);
			}
		}
		// both still have army remaining  
		if (attacker.getArmy() > 1 && defender.getArmy() > 0)
		{
			//defence has 2 dice so fight continue 
			if (defenderDices == 2)
			{
				if (attackRoll2 == defenceRoll2)
				{
					attacker.setArmy(attacker.getArmy() - 1);
				}
				else
				{
					if (attackRoll2 > defenceRoll2)
					{
						defender.setArmy(defender.getArmy() - 1);
					}
					else if (attackRoll2 < defenceRoll2)
					{
						attacker.setArmy(attacker.getArmy() - 1);
					}
				}
			}
		}
		return attackerDices; // when win , need to know how many dice
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
void Battle::winner(int DiceUsedbyAttack, Country& attacker, Country& defender){

	defender.setOwner(attacker.getOwner());
	cout << "\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!---WINNER ---!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	cout << "\nAttacker has won, he is the new owner of " << defender.getName() << endl;

	int moveArmy;
	//how you many soldier in new Country
	cout << "you have " << attacker.getArmy() << " remaining in your winner Country " << endl;
	cout << "how many army do you wish to move to your new Country ? ";
	cin >> moveArmy;

	// Conditions to how many army the winning country can send to her new country
	while (moveArmy < DiceUsedbyAttack || moveArmy > attacker.getArmy() || moveArmy == attacker.getArmy())
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
void Battle::blitz(Country& attacker, Country& defender)
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
		if (defender.getArmy() ==0)
		{
			//attacker won
			winner(DiceUsedbyAttack ,attacker, defender);
			break;
		}

	}
}
/**
*	skirmish : one single fight
*   @param Country& attacker, defender	reference to the attacking and defending country 
*/
void Battle::skirmish(Country& attacker, Country& defender)
{
	while (true)
	{
		//executing the fight
		int DiceUsedbyAttack = fight(attacker, defender);
		//cout << "test" << attacker.getArmy() << endl;
		//RESULT
		if (defender.getArmy() == 0)
		{
			//attacker won
			winner(DiceUsedbyAttack, attacker, defender);
			break; //stop skrmish 
		}
		else
		{
			status(attacker, defender);
			if (attacker.getArmy() == 1)
			{
				loser();
				break;
			}
			int choice=3;
			while (choice != 1 && choice != 2)
			{
			cout << "Do you which to continue the fight or stop ---  (continue = 1, stop = 2)";
			cin >> choice;
			}
			
			if (choice == 1)
			{
				//continue while true
				//
			}
			else if (choice == 2)
			{
				//stop fight
				break;
			}
		}
	}
}
/**
*	Show all the valid action available during the war phase
*   @param Country& attacker, defender	reference to the attacking and defending country 
*/
void Battle::war(Country& attacker, Country& defender)
{
	int choice = -1;
	while (choice !=0 && choice !=1 && choice !=2)
	{
		cout << "\n-----------------------------------------------------" << endl;
		cout << "choose a war option: " << endl;
		cout << "0 --> skirmish" << endl;
		cout << "1 --> blitz (all in attack mode) " << endl;
		cout << "2---> exit" << endl;
		cout << "select ==> ";
		cin >> choice;
	}
	switch (choice)
	{
	case 0: skirmish(attacker, defender);
		break;
	case 1: blitz(attacker, defender);
		break;
	case 2: //exit 
		break;
	}
}