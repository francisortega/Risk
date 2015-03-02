/* 
 * File:   StartupPhase.cpp
 * Author: ubuntu
 * 
 * Created on January 27, 2015, 2:59 PM
 */
#include <iostream>
#include <stdlib.h>
#include "StartupPhase.h"
using namespace std;


StartupPhase::StartupPhase() {
}

StartupPhase::StartupPhase(const StartupPhase& orig) {
}

StartupPhase::~StartupPhase() {
}

void StartupPhase::assignRandomCountry(Player players [], Country countries [], string playerNames [], int numOfPlayers){
    
    
    int previouslyGenerated [numOfPlayers];
    for (int i=0; i<numOfPlayers; i++){
        //99 means non valid in our case
        previouslyGenerated[i]=99;
    }
    
    
    cout << "Players are now being assigned random a country" << endl;
    //assign random countries to players
    int i=0;
    bool selectionExist=false;
    while (i<numOfPlayers){
        //it chooses a random number, the checks if that number has been generated before
        //if the number has been generated before it means that the player relative to the generated number has been assigned a country already
        srand ( time(NULL) );
        int randomSelection=rand() % 4;
        for (int j=0; j<i; j++){
        if (randomSelection==previouslyGenerated[j]){
            selectionExist=true;
        }
        }
        if (!selectionExist){
            players[i].name=playerNames[randomSelection];
            players[i].countries[0].name=countries[i].name;
             previouslyGenerated[i]=randomSelection;
            i++;
        }
        
        selectionExist=false;
    }
     cout << "Here are the players and their assigned countries:\n";
    for(int i=0; i<numOfPlayers; i++)

   {

      cout << players[i].name << ": " << players[i].countries[0].name << endl;

   }
}
