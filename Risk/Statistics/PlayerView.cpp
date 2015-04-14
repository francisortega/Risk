/* 
 * File:   PlayerView.cpp
 * Author: ubuntu
 * 
 * Created on February 18, 2015, 8:12 PM
 */

#include "PlayerView.h"
#include "Statistics.h"
#include "BasicStats.h"
#include "Observer.h"

#include <string>
#include <iostream>
using namespace std;

PlayerView::PlayerView() {
	this->stat = new BasicStats();
}

PlayerView::PlayerView(const PlayerView& orig) {
}

PlayerView::~PlayerView() {
}

void PlayerView::update(){
	this->stat->printStats(); 
}


