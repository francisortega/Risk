/**
 *
 * @author  Francis Ortega 1295578
 * @author  Michal Wozniak 1941097
 * @author  Darren Mau 6057993
 * @author  Francis Cote-Tremblay 6615287
 * @date    03-05-2015
 * @version project v1
 */
#ifndef STARTUPPHASE_H
#define	STARTUPPHASE_H

#include "Country.h"
#include "Player.h"

class StartupPhase {
public:
	void static assignRandomCountry(vector<Country> *world, list<Player> *players);
	void static initialFortification(vector<Country> *world, list<Player> *players);
	static list<Player> setPlayerNames();
	StartupPhase();
	StartupPhase(const StartupPhase& orig);
	virtual ~StartupPhase();

};

#endif	/* STARTUPPHASE_H */
