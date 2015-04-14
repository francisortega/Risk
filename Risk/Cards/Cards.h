#pragma once
#include <list>
using namespace std;

class Cards
{
public:
	Cards();
	~Cards();

	enum cardType { INFANTRY, CAVALRY, ARTILLERY };
	int nbSetTraded;


	void add(); // add one card

	void viewCardsList();
	void doTradeIn(int card1, int card2, int card3);

	//Player can only draw one card for each turn
	bool hasAlreadyCaptureOneCountry;

	//TODO : reset when user's turn end 
	void resetAlreadyCaptureOneCountry();
	void setCaptureOneCountry();

	bool isTradeInPossibleNow();
	bool mustTradeInNow();

	void verifyTradeInPosibility();
	//get the value of the future card trade in; How much army you will get for your exchange
	int getNextCardTradeInArmyValue();

	list<cardType>* getCardList();
	void setCardList(list<cardType> cardList);
	/*

	Earning Cards. At the end of any turn in which you have captured at
	least one territory, you will earn one (and only one) RISK card. You are
	trying to collect sets of 3 cards in any of the following combinations:

	


	*/


private:

	list<cardType> cardList;
	cardType createCard();
	int numberOfCards;
	bool isTradeInPossible;
	bool mustTradeIn;
	void setNumberofCards(int newSize);
	

	



};

