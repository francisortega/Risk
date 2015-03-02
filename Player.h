/* 
 * File:   Player.h
 * Author: ubuntu
 *
 * Created on January 26, 2015, 3:14 PM
 */
#include <iostream>
#include "Country.h"
using namespace std;
#ifndef PLAYER_H
#define	PLAYER_H

class Player {
public:
    string name;
    Country countries [10];
    int armies;
    Player();
    Player(const Player& orig);
    virtual ~Player();
private:

};

#endif	/* PLAYER_H */

