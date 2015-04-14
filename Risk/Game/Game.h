/**
 * @author  Darren Mau 6057993
 * @date    04-08-2015
 * @assignment 3
 */

//Game is the product.
#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "../Map/Map.h"
#include "../GamePlay/GamePlay.h"
#include "../SaveAndLoad.h"

class Game
{
	public:
		//Set all parts of the Game, and use the Game.
		void setMap(const Map& map);
		void setGamePlay(const GamePlay& gameTurn);
		//Save the game into a file.
		void saveGame();
		//Load the game from a file.
		void loadGame();
		//Return map
		Map getMap();
		//Return gameTurn
		GamePlay getGamePlay();

	private:
		//get the card number from their name
		string getCardNumber(Cards::cardType& index);
		//read the territory and add it to the map
		void readTerritory(Map* map, vector<string>* name, vector<vector<string>>* adjCountries,string str, int id);
		//read the player and add it to player
		void readPlayer(Player* player, string str,Cards* cards);
		//Part of the Game
		Map map;
		GamePlay gamePlay;

};
