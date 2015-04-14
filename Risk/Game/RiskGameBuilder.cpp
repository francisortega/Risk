/**
 * @author  Darren Mau 6057993
 * @date    04-08-2015
 * @assignment 3
 */
//Concrete Builder.
#include"RiskGameBuilder.h"

/**
 * Build the map of the game
 */
void RiskGameBuilder::buildMap(Map* map)
{
	game->setMap(*map);
}

/*
 *Build the Game's player's turn
 */
void RiskGameBuilder::buildGameTurn(GamePlay* gameTurn)
{
	game->setGamePlay(*gameTurn);
}