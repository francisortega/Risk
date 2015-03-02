/* 
 * File:   MainPhase.cpp
 * Author: ubuntu
 * 
 * Created on January 27, 2015, 2:59 PM
 */

#include "MainPhase.h"
#include "Player.h"
#include <iostream>
#include <limits>
using namespace std;



MainPhase::MainPhase() {
    
}

MainPhase::MainPhase(const MainPhase& orig) {
}

MainPhase::~MainPhase() {
}

    
     void MainPhase::reinforce(Player *player, int numOfPlayers){
        int countryToReinf=0;
        int armiesToReinf=0;
        
        cout << endl;
        cout << "Reinforcment phase begins for the following player:" << player->name << endl;
        cout << "You've been assigned 5 more armies" << endl;
        player->armies=+5;
        cout << "FORTIFICATION: your countries are:"<< endl;
        for (int j=0; j< numOfPlayers; j++){
            cout << j << ":  " << player->countries[j].name << endl;
        }
        cout << "Enter the number of the country you wish to reinforce" << endl;
        cin >> countryToReinf; 
        while (countryToReinf>=numOfPlayers || countryToReinf<0 || !cin.good()){
             cout << "Enter an integer between the number given earlier\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> countryToReinf;
        }
        cout << "The number of armies available is:  " << player->armies << endl;
        cout << "Enter the number of armies you wish to use to reinforce" << endl;
        cin >> armiesToReinf;
        while (armiesToReinf>player->armies || armiesToReinf<0 || !cin.good()){
             cout << "Enter an integer between below or equal to the number of armies given\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> armiesToReinf;
        }
    }
    
    void MainPhase::attack(Player *player, Player players [], int numOfPlayers){
        cout << endl;
        cout << "Attack phase begins for the following player:" << player->name << endl;
        //ATTACK PHASE
         cout << "ATTACK: Here are the players and their assigned countries:\n";
   
         for(int k=0; k<numOfPlayers; k++)

   {
                        
      cout << players[k].name << ": ";
      for (int l=0; l<numOfPlayers; l++){
          cout << players[k].countries[l].name << " --- ";
      }
      cout << endl;
   }
         cout << endl;
         
    }
    
   void MainPhase::fortification(Player *player, int numOfPlayers){
        cout << endl;
        
        cout << "Fortification phase begins for the following player:" << player->name << endl;
        string whatever;
        cout << "This is a non working method, press any key to continue.." << endl;
        cin >> whatever;
        
        cout << endl;
    }

