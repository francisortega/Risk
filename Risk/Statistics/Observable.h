/* 
 * File:   Observable.h
 * Author: ubuntu
 *
 * Created on February 18, 2015, 7:54 PM
 */

#ifndef OBSERVABLE_H
#define	OBSERVABLE_H


#include <list>
using namespace std;

#include "Observer.h"

class Observable {
public:
    Observable();
    Observable(const Observable& orig);
    virtual ~Observable();
    void notify();
    void attach(Observer *);
    void detach(Observer *);
	list<Observer*> getObservers();
    list<Observer*> observers;  

};

#endif	/* OBSERVABLE_H */

