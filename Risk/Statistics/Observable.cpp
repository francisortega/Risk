#include <iostream>
#include <string>
using namespace std;
#include "Observable.h"

Observable::Observable() {
}

Observable::Observable(const Observable& orig) {
}

Observable::~Observable() {
}

void Observable::attach(Observer *ob){
    observers.push_front(ob);
}
void Observable::detach(Observer *ob){
    observers.remove(ob);
}
list<Observer*> Observable::getObservers(){
	return this->observers;
}

void Observable::notify(){
    list<Observer *>:: iterator i= observers.begin();
    for (; i!=observers.end();++i){
        (*i)->update();
    }
}

