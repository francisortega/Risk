/**
 * @author  Darren Mau 6057993
 * @date    04-08-2015
 * @assignment 3
 */

//Game is the product.
#include "Game.h"

/**
 *	Set the game map.
 */
void Game::setMap(const Map& map)
{
	this->map = map;
}

/**
 * 	Set the game turn.
 */
void Game::setGamePlay(const GamePlay& gamePlay)
{
	this->gamePlay = gamePlay;
}

/**
 * get the card number from their name
 */
string Game::getCardNumber(Cards::cardType& index)
{
	string name = "";
	switch (index)
	{
		case Cards::INFANTRY: 
			name = "0";
			break;
		case Cards::CAVALRY:
			name = "1";
			break;
		case Cards::ARTILLERY:
			name = "2";
			break;
	}
	return name;
}

/**
 *	Save the game into a file.
 */
void Game::saveGame()
{
	ofstream myfile ("Game.map");
	if (myfile.is_open())
	{
		myfile << "[Continents]\n";
		vector<Map::Continent> continents = map.getContinents();
		for(size_t n=0; n < continents.size(); n++)
		{
			myfile << continents[n].name <<"=" <<continents[n].extra << "\n";
		}
		myfile << "\n";
		myfile << "[Territories]\n";
		vector<Country>* countries = map.getWorldMap();
		for(size_t n=0; n < countries->size(); n++)
		{
			//line break if it is a new continent
			if(n > 0 && countries->at(n-1).getContinent() != countries->at(n).getContinent())
			{
				myfile << "\n";
			}
			myfile << countries->at(n).getName() << ",";
			myfile << countries->at(n).getX() << ",";
			myfile << countries->at(n).getY() << ",";
			myfile << countries->at(n).getContinent() << ",";
			myfile << countries->at(n).getOwner() << ",";
			myfile << countries->at(n).getArmy() << ',';
			vector<Country> adjCountries = map.getAdjacentCountries(countries->at(n).getName(), "all");
			for(size_t i=0; i < adjCountries.size() -1; i++)
			{
				myfile << adjCountries[i].getName() << ",";
			}
			myfile << adjCountries[adjCountries.size() -1].getName() << "\n";
		}
		myfile << "\n";
		myfile << "[Player]\n";
		vector<Player*>* player = gamePlay.getPlayers();
		for(size_t i=0; i < player->size(); i++)
		{
			myfile << player->at(i)->getName() << ",";
			//check if it is a computer
			if(player->at(i)->getComputer().size() > 0)
			{
				myfile << player->at(i)->getComputer() << ",";
			}
			//if its not a computer, a space will be saved instead.
			else
			{
				myfile << " ,";
			}
			list<Cards::cardType>* cardList = player->at(i)->getCards()->getCardList();
			while(cardList->size() != 1)
			{
				string name = getCardNumber(cardList->front());
				myfile << name << ",";
				cardList->pop_front();
			}
			string name = getCardNumber(cardList->front());
			myfile << name << "\n";
		}
		myfile << "\n";
		myfile << "[Turn]\n";
		myfile << gamePlay.getPlayerTurn() << "\n";
		myfile.close();
	}
	else 
	{
		cout << "Unable to open file";
	}
}

/**
 * read the territory and add it to the map.
 */
void Game::readTerritory(Map* map, vector<string>* name, vector<vector<string>>* adjCountries,string str, int id)
{
	vector<string> territories = SaveAndLoad::split(str, ',');
	vector<string> country1;
	name->push_back(territories[0]);
	//Adjacent country start at the 6th.
	for(size_t n=6; n < territories.size(); n++)
	{
		country1.push_back(territories[n]);
	}
	
	adjCountries->push_back(country1);
			
	int x;
	istringstream ( territories[1] ) >> x;
	int y;
	istringstream ( territories[2] ) >> y;

	map->addCountry(id, territories[0], territories[3],x,y);
	map->get(territories[0])->setOwner(territories[4]);
	int army;
	istringstream ( territories[5] ) >> army;
	map->get(territories[0])->setArmy(army);
}

/**
 * read the player and add it to player
 */
void Game::readPlayer(Player* player, string str,Cards* cards)
{
	vector<string> splitWords = SaveAndLoad::split(str, ',');
	list<Cards::cardType> cardList;
	player->setName(splitWords[0]);
	//if it is not a space it is a computer
	if(splitWords[1] != " ")
	{
		player->setComputer(splitWords[1]);
	}
	//Add all the card to the card list.
	for(size_t n=2; n < splitWords.size(); n++)
	{
		int number;
		istringstream ( splitWords[n] ) >> number;
		Cards::cardType card;
		switch (number)
		{
			case 0: card = Cards::cardType::INFANTRY;
				break;
			case 1: card = Cards::cardType::CAVALRY;
				break;
			default: card = Cards::cardType::ARTILLERY;;
				break;
		}
		cardList.push_back(card);
	}
	cards->setCardList(cardList);
}

/**
 *	Load the game from a file.
 */
void Game::loadGame()
{
	Map map;
	GamePlay gameTurn;
	int id = 0;
	try
	{
		ifstream file("Game.map");
		string str;
		bool isContinent = false;
		bool isTerritorie = false;
		bool isPlayer = false;
		bool isTurn = false;
		vector<string> territories;
		vector<string> name;
		vector<vector<string>> adjCountries;
		vector<string> continent;
		vector<Player*>* players = new vector<Player*>();

		while (getline(file, str))
		{
			
			if(isContinent == true && str[0] != '[' && str.length() > 0)
			{
				continent = SaveAndLoad::split(str, '=');
				int num;
				istringstream ( continent[1] ) >> num;
				map.addContinents(continent[0], num);
			}
			
			if(isTerritorie == true && str[0] != '[' && str.length() > 0)
			{
				readTerritory(&map, &name, &adjCountries, str, id);
				++id;
			}

			if(isPlayer == true && str[0] != '[' && str.length() > 0)
			{
				Player* player = new Player();
				Cards* cards = new Cards();
				readPlayer(player, str,cards);
				player->setCards(cards);
				players->push_back(player);
			}

			if(isTurn == true && str[0] != '[' && str.length() > 0)
			{
				int number;
				istringstream ( str ) >> number;
				gameTurn.setPlayerTurn(number);
			}
			
			if(str[0] == '[')
			{
				if(str == "[Continents]")
				{
					isContinent = true;
					isTerritorie = false;
					isPlayer = false;
					isTurn = false;
				}
				else if(str == "[Territories]")
				{
					isContinent = false;
					isTerritorie = true;
					isPlayer = false;
					isTurn = false;
				}
				else if(str == "[Player]")
				{
					isContinent = false;
					isTerritorie = false;
					isPlayer = true;
					isTurn = false;
				}
				else
				{
					isContinent = false;
					isTerritorie = false;
					isPlayer = false;
					isTurn = true;
				}
			}
		}

		for(size_t n=0; n < adjCountries.size(); n++)
		{
			map.addAdjacency(name[n], adjCountries[n]);
		}
		gameTurn.setPlayers(players);
		this->gamePlay = gameTurn;
		this->map = map;
		file.close();
	}
	catch (exception& e)
	{
		cout << e.what() << '\n';
	}
	
}

/**
 * Return map.
 */
Map Game::getMap()
{
	return map;
}

/**
 * Return gameTurn
 */
GamePlay Game::getGamePlay()
{
	return gamePlay;
}