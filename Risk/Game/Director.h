/**
 * @author  Darren Mau 6057993
 * @date    04-08-2015
 * @assignment 3
 */
//Director is responsible for the whole process.
#pragma once
#include "GameBuilder.h"

class Director
{
	public:
		//Concrete builder for building a specific kind of game.
		void setGameBuilder(GameBuilder* gameBuilder);
		//get the constructed Game.
		Game* getGame();
		//Creational process to create a game using the builder.
		void constructGame(Map* map, GamePlay* gameTurn);

	private:
		GameBuilder* gameBuilder;
};