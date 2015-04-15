#include "MapEditor.h"

//The function will create the map depending on the choice.
bool MapEditor::createMap(Map &map,string choose, string name)
{ 
	SaveAndLoad s;
	int num;
	istringstream (choose ) >> num;
	switch(num)
	{
	//create the map.
	case 1: createContinent(map);
		break;
	//get map from file.
	case 2:  s.load(map, name);
		break;
	}

	//return true if map is valide.
	if (s.validate(map))
	{
		return true;
	}
	//return false if map is invalide.
	else
	{
		return false;
	}
}

//The function will create the continent.
void MapEditor::createContinent(Map &map)
{
	string cont = "";
	string temp;
	string temp1;
	int num;
	//loop until finish creating continent.
	do
	{
		cin.sync();
		cout << "New continent name: ";
		getline(cin, cont);
		cout << "Extra army number: ";
		cin >> num;
		while (!cin) {
			cout << "ERROR, enter a number: \n" ;
			cin.clear();
			cin.ignore(256,'\n');
			cin >> num;
		}
		map.addContinents(cont,num);
		temp = answer("Continent");
	}while (temp != "N" && temp != "n");
	createCountry(map);
}

//The function will create the country.
void MapEditor::createCountry(Map &map)
{
	string countryName;
	int num = 0;
	string input = "";
	int choice;
	string temp = "";
	vector<Map::Continent> continent = map.getContinents();
	int size = continent.size();

	//loop until finish creating country.
	do
	{
		cin.sync();
		cout << "New country name: " ;
		getline(cin, countryName);
		cout << "Continent: " << endl;
		for(int n=0; n < size; n++)
		{
			cout <<n << " " << continent[n].name << endl;
		}
		cout << "Which continent: " << endl;
		choice = checkInt(size);
		map.addCountry(num, countryName, continent[choice].name,0,0);
		++num;
		temp = answer("Country");		
	}while (temp != "N" && temp != "n");
	
	createAdjacent(map);
}

//The function will create the adjacent.
void MapEditor::createAdjacent(Map &map)
{
	vector<Country>* country = map.getWorldMap();
	int size = country->size();
	string input = "";
	int choice;
	string temp = "";
	
	//loop throught the map.
	for(size_t i = 0; i < country->size(); ++i)
	{
		vector<string> c;
		for(int n=0; n < size; n++)
		{
			cout <<n << ". " << country->at(n).getName() << endl;
		}
		cout << "Add " <<  country->at(i).getName() <<  " Adjacent:" << endl;	
		//loop until finish choosing the adjacent
		do
		{
			choice = checkInt(size);
			c.push_back(country->at(choice).getName());
			map.addAdjacency(country->at(i).getName(), c);
			temp = answer("adjacent");
		} while (temp != "N" && temp != "n");

	}
	
}

//The function will return the answer.
string MapEditor::answer(string name)
{
	string temp = "";
	//loop until the user type Y,y,N,n.
	do
	{
		cout << "Continue adding " << name << "? Y/N" << endl;
		cin >> temp;
	} while(temp != "Y" && temp != "y" && temp != "N" && temp != "n");
	return temp;
}

//The function will return the choice.
int MapEditor::checkInt(int size)
{
	string input = "";
	int choice = 0;
	//loop until the user input a number bigger than 0 and smaller than size.
	while (true) {
		getline(cin, input);
		// This code converts from string to number safely.
		stringstream myStream(input);
		if (myStream >> choice && (choice >= 0 && choice < size))
		{
			break;
		}
		cout << "Please enter a number: ";
	}
	return choice;
}