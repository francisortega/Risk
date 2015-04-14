/**
 * @author  Darren Mau 6057993
 * @date    04-08-2015
 * @assignment 3
 */
//Abstract class providing the structure for all
//concrete Game builders.
#include "GameBuilder.h"

/**
 *	get the build game from the builder.
 */
Game* GameBuilder::getGame()
{
	return game;
}

/**
 *	build a generic empty game
 */
void GameBuilder::createNewGame()
{
	game = new Game;
}


