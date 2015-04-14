/* 
 * File:   PlayerView.h
 * Author: ubuntu
 *
 * Created on February 18, 2015, 8:12 PM
 */

#ifndef PLAYERVIEW_H
#define	PLAYERVIEW_H

#include "Observer.h"
#include "Observable.h"
#include "Statistics.h"
#include "StatDecorator.h"

class PlayerView: public Observer {
public:
    PlayerView();
    PlayerView(const PlayerView& orig);
    virtual ~PlayerView();
    void update();
	void replaceDecorator();
    Statistics *stat;
};

#endif	/* PLAYERVIEW_H */

