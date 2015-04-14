/**
 * @author  Darren Mau 6057993
 * @date    04-08-2015
 * @assignment 3
 */
//Abstract class providing the structure for all
//concrete Game builders.
#pragma once
#include "Game.h"

class GameBuilder
{
	public:
		//get the build game from the builder
		Game* getGame();
		//build a generic empty game
		void createNewGame();
		//Create each part of the game
		virtual void buildMap(Map* map) = 0;
		virtual void buildGameTurn(GamePlay* gameTurn) = 0;

	protected:
		//Product build by Game builder
		Game* game;
};