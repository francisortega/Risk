/* 
 * File:   Country.h
 * Author: ubuntu
 *
 * Created on January 27, 2015, 8:52 AM
 */
#include <iostream>
using namespace std;

#ifndef COUNTRY_H
#define	COUNTRY_H

class Country {
public:
    string name;
    int armies;
    Country();
    Country(const Country& orig);
    virtual ~Country();
private:

};

#endif	/* COUNTRY_H */

