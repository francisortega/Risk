#include <time.h>
#include <string>
#include "Cards.h"
#include <iostream>
using namespace std;


//The first set traded in - 4 armies
//The second set traded in - 6 armies
//The third set traded in - 8 armies
//The fourth set traded in - 10 armies
//The fifth set traded in - 12 armies
//The sixth set traded in - 15 armies
//every set after + 5 to previous set = total

Cards::Cards()
{
	this->isTradeInPossible = false;
	this->mustTradeIn = false;
	this->numberOfCards = 0;
	this->nbSetTraded = 0;
	this->hasAlreadyCaptureOneCountry = false;
}


Cards::~Cards()
{
}


void Cards::setCaptureOneCountry()
{
	this->hasAlreadyCaptureOneCountry = true;
}
void Cards::resetAlreadyCaptureOneCountry()
{
	this->hasAlreadyCaptureOneCountry = false;
}


int Cards::getNextCardTradeInArmyValue()
{
	int nextTrade = nbSetTraded + 1;

	int value;
	switch (nextTrade)
	{
	case 1:  value = 4;
		break;
	case 2:	value = 6;
		break;
	case 3:	value = 8;
		break;
	case 4:	value = 10;
		break;
	case 5: value = 12;
		break;
	case 6: value = 15;
		break;
	default:
		int howManyAfter6th = nextTrade - 6;
		int extra = howManyAfter6th * 5; //every set after the 6th get +5 more than previous 
		value = 15 + extra;

	}
	return value;
}

Cards::cardType Cards::createCard()
{
	 //random -> range [1,3]
	 int random = (rand() % 3);

	 
	 //cardType type = cardType::INFANTRY;

	 cardType card;
	 switch (random)
	 {
	 case 0:	card = INFANTRY;
		 cout << "You have draw a Infantrtry card "<< endl;
		 break;
	 case 1:	card = CAVALRY;
		 cout << "You have draw a Cavalry card " << endl;
		 break;
	 default:	card = ARTILLERY;;
		 cout << "You have draw a Artillery card " << endl;
	 }

	 return card;

}

void Cards::setNumberofCards(int newSize)
{
	this->numberOfCards = newSize;
}


/*
	add one random card to user card list
*/
void Cards::add()
{

	this->cardList.push_back(createCard());
	this->setNumberofCards(this->cardList.size());

}

void Cards::verifyTradeInPosibility()
{
	int typeInfantry =0, typeCavalry=0, typeArtillery = 0;

	for (auto& index : cardList)
	{
		switch (index)
		{
		case  INFANTRY: typeInfantry += 1;
			break;
		case CAVALRY:	typeCavalry += 1;
			break;
		case ARTILLERY:	typeArtillery += 1;
			break;
		}
	}

	if (this->numberOfCards >= 5)
	{
		this->mustTradeIn = true;
	}
	else
	{
		this->mustTradeIn = false;
	}

	if (typeInfantry >= 1 && typeCavalry >= 1 && typeArtillery >= 1 || typeInfantry >= 3 || typeCavalry >= 3 || typeArtillery >= 3)
	{
		this->isTradeInPossible = true;
	}
	else
	{
		this->isTradeInPossible = false;
	}
}

/*
	The purpose of this function is to remove the selected card from the user list of card
	@param card1,card2,card3 user will choose 3 card that will have a specific type 
*/
void Cards::doTradeIn(int card1, int card2, int card3)
{
	int cardLeft = 3;

	//Enum have a associated value when they are initialized 
	//0 = INFANTRY
	//1= CAVALRY
	//2=ARTILLERY

	//http://stackoverflow.com/questions/2047414/advantages-of-stdfor-each-over-for-loop
	for (auto i = this->cardList.begin(); i != this->cardList.end();)
	{
		if (cardLeft != 0)
		{
			if (*i == (cardType)card1)
			{
				i = this->cardList.erase(i);
				cardLeft--; //decrease when card was used
			}
			if (*i == (cardType)card2)
			{
				i = this->cardList.erase(i);
				cardLeft--;
			}
			if (*i == (cardType)card3)
			{
				i = this->cardList.erase(i);
				cardLeft--;
			}

		}
		else
		{
			//increasing here if didn't delete
			i++;
		}
	}
	//set new size after used card were delete
	this->setNumberofCards(this->cardList.size());

	//user has tradeIn some card; increase the counter
	this->nbSetTraded += 1; 
}

void Cards::viewCardsList()
{
	//counter
	int infantry, cavalry, artillery =0;

	cout << "You have these card in your posession : " << endl;

	//print the list of cards
	for (auto& index : cardList)
	{
		switch (index)
		{
		case  INFANTRY: infantry += 1;
			cout << "infantry ";
			break;
		case CAVALRY:	cavalry += 1;
			cout << "cavalry ";
			break;
		case ARTILLERY:	artillery += 1;
			cout << "artillery ";
			break;
		}
	}
	//stats output 
	cout << "\n Stats ---- INFANTRY :" << infantry << " ---- CAVALRY :" << cavalry << " ----ARTILLERY :" << artillery << endl;;
}

bool Cards::isTradeInPossibleNow()
{
	return this->isTradeInPossible;
}
bool Cards::mustTradeInNow()
{
	return this->mustTradeIn;
}

list<Cards::cardType>* Cards::getCardList()
{
	return &cardList;
}

void Cards::setCardList(list<cardType> cardList)
{
	this->cardList = cardList;
}