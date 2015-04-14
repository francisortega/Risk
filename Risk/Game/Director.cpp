/**
 * @author  Darren Mau 6057993
 * @date    04-08-2015
 * @assignment 3
 */
//Director is responsible for the whole process.
#include "Director.h"

/**
 * Concrete builder for building a specific kind of game.
 */
void Director::setGameBuilder(GameBuilder* gameBuilder)
{
	this->gameBuilder = gameBuilder;
}

/**
 * get the constructed Game.
 */
Game* Director::getGame()
{
	return gameBuilder->getGame();
}

/**
 * Creational process to create a game using the builder.
 */
void Director::constructGame(Map* map, GamePlay* gameTurn)
{
	gameBuilder->createNewGame();
	gameBuilder->buildMap(map);
	gameBuilder->buildGameTurn(gameTurn);
}
