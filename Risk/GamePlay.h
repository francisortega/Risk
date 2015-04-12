#pragma once
#include <deque>
#include "Player.h"

class GamePlay
{

	
	
	
	
	
	




public:
	GamePlay();
	~GamePlay();

	deque <Player*> playerRoundLoop;
private :
	int turnCounter= 1;
	bool gameOver = false; // when one user remain
	int nbOfPlayer;


	//http://www.cplusplus.com/reference/deque/deque/
	//deque (usually pronounced like "deck") is an irregular acronym of double-ended queue
	//deque <Player*> playerRoundLoop;
	//deque 

	
	void setNbOfPlayer();
	int getNbOfPlayers();

	bool getGameOver();
	void setGameOver();

	void menu();

	void gameFlow();



};

