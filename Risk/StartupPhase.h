#ifndef STARTUPPHASE_H
#define	STARTUPPHASE_H

#include "Player.h"
#include "Country.h"

class StartupPhase {
public:
	void static assignRandomCountry(vector<Country> world, list<string> playerNames, const int numOfPlayers);
	StartupPhase();
	StartupPhase(const StartupPhase& orig);
	virtual ~StartupPhase();
private:

};

#endif	/* STARTUPPHASE_H */
