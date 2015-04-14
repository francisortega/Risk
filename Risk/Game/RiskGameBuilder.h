/**
 * @author  Darren Mau 6057993
 * @date    04-08-2015
 * @assignment 3
 */
//Concrete Builder.
#pragma once
#include "GameBuilder.h"
class RiskGameBuilder : public GameBuilder
{
	public:
		//Build the map of the game
		virtual void buildMap(Map* map);
		//Build the Game's player's turn
		virtual void buildGameTurn(GamePlay* gameTurn);
};