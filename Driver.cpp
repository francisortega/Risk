/* 
 * File:   main.cpp
 * Author: ubuntu
 *
 * Created on January 12, 2015, 3:55 AM
 */

#include <cstdlib>
#include <iostream>
#include <limits>
#include <map>
#include <stdlib.h>
#include "Player.h"
#include "MainPhase.h"
#include "StartupPhase.h"

using namespace std;

/*
 * 
 */
int main() {
    
    //STARTUP PHASE **********************************
    
    //The number of players will be used throughout the game. It cannot be more than 4
    //at the moment in order to limit the number of countries that need to be used to 
    //run the driver.
    
    //Additionally players can only stick with their initial country they were assigned
    //since this we did not need to implement the phases inside the main phase.
    int numOfPlayers;
    
        cout << "How many players? (Max 4 players)\n";
    cin >> numOfPlayers;
    while (numOfPlayers<=0 || numOfPlayers>4 || !cin.good()){
        cout << "Enter an integer between 1 and 4\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> numOfPlayers;
    }
    
    string playerNames [numOfPlayers];
    Country countries [numOfPlayers];
    countries[0].name="CA";
    countries[1].name="RU";
    countries[2].name="US";
    countries[3].name="UK";
    Player players [numOfPlayers];
     
    
    
    //This is setting the name of each player.
    for (int i=1; i<=numOfPlayers; i++){
        cout << "Enter player " << i << " name:\n";
        cin >> playerNames[i-1];
    }

    
   
    //This methos uses rand to assign a random player to a country.
    //The name of this method does not do exactly what its name says. Instead of assigning
    //a country to a player it assign a player to a country. It was faster and easier to implement this way.
    StartupPhase::assignRandomCountry(players, countries, playerNames, numOfPlayers);
    
   

    //END STARTUP PHASE 
    //MAIN PHASE *****************************************
    
    //This is round robin based. Players play one after another. 
    for (int i=0;i<numOfPlayers;i++){
        //reinforce has been implemented as an example but it is not fully working.
        MainPhase::reinforce(&players[i], numOfPlayers);
        //attack is partly implemented but it has no action.
        MainPhase::attack(&players[i], players, numOfPlayers);
        //fortification is not implemented
        MainPhase::fortification(&players[i], numOfPlayers);
    }
    
    
    
    return 0;
}

