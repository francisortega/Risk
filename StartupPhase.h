/* 
 * File:   StartupPhase.h
 * Author: ubuntu
 *
 * Created on January 27, 2015, 2:59 PM
 */

#ifndef STARTUPPHASE_H
#define	STARTUPPHASE_H

#include "Player.h"
#include "Country.h"

class StartupPhase {
public:
    void static assignRandomCountry(Player players [], Country countries [], string playerNames [], int numOfPlayers);
    StartupPhase();
    StartupPhase(const StartupPhase& orig);
    virtual ~StartupPhase();
private:

};

#endif	/* STARTUPPHASE_H */

