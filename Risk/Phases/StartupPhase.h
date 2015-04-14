/**
*
* @author  Francis Ortega 1295578
* @author  Michal Wozniak 1941097
* @author  Darren Mau 6057993
* @author  Francis Cote-Tremblay 6615287
*/
#ifndef STARTUPPHASE_H
#define	STARTUPPHASE_H

#include "../Map/Country.h"
#include "../Player/Player.h"
#include "../Map/Map.h"

class StartupPhase {
public:
	void assignRandomCountry(list<Player> *players);
	void initialFortification(list<Player> *players);
	list<string> createPlayerNames(list<Player> *players);
    list<Player> setPlayerNames();
	StartupPhase(Map *map);
	StartupPhase(const StartupPhase& orig);
	virtual ~StartupPhase();
private:
	Map *currentMap;

};

#endif	/* STARTUPPHASE_H */