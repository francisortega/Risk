/* 
 * File:   MainPhase.h
 * Author: ubuntu
 *
 * Created on January 27, 2015, 2:59 PM
 */

#ifndef MAINPHASE_H
#define	MAINPHASE_H

#include "Player.h"


class MainPhase {
public:
    MainPhase();
    static void reinforce(Player *player, int numOfPlayers);
    static void attack(Player *player,Player players [], int numOfPlayers);
    static void fortification(Player *player, int numOfPlayers);
    MainPhase(const MainPhase& orig);
    virtual ~MainPhase();
private:

};

#endif	/* MAINPHASE_H */

