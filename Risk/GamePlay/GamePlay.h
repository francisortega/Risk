#pragma once
#include <deque>
#include "../Player/Player.h"
#include "../SaveAndLoad.h"

class GamePlay
{


public:
	GamePlay();
	~GamePlay();

	deque <Player*> playerRoundLoop;
	//set the list of player.
	void setPlayers(vector<Player*>* players);
	// return the list of player.
	vector<Player*>* getPlayers();
	int getPlayerTurn();
	void setPlayerTurn(int playerTurn);
private :
	int turnCounter;
	int playerTurn;
	bool gameOver; // when one user remain
	int nbOfPlayer;
	vector<Player*>* players;
	vector<Country> *world;


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

