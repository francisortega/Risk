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

#include "Player.h"
#include "Country.h"

class StartupPhase {
public:
	void static assignRandomCountry(vector<Country> &world, list<string> playerNames, const int numOfPlayers);
	StartupPhase();
	StartupPhase(const StartupPhase& orig);
	virtual ~StartupPhase();
private:

};

#endif	/* STARTUPPHASE_H */
