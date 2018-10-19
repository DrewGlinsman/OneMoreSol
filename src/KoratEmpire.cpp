/*
 * KoratEmpire.cpp
 *
 *  Created on: Oct 14, 2018
 *      Author: jabowden
 */

#include <KoratEmpire.h>

KoratEmpire::KoratEmpire() {
	// TODO Auto-generated constructor stub

}

KoratEmpire::~KoratEmpire() {
	// TODO Auto-generated destructor stub
}

unsigned int KoratEmpire::getHealth() const {
	return health;
}

void KoratEmpire::setLane(int givenLane)
{
    switch(givenLane)
	{
		case 1:
			lane = lane1;
			break;
		case 2:
			lane = lane2;
			break;
		case 3:
			lane = lane3;
			break;
		case 4:
			lane = lane4;
			break;
		case 5:
			lane = lane5;
			break;
		default:
			lane = lane1;
			break;
	}
}

int KoratEmpire::getLane()
{
	return lane;
}

void KoratEmpire::setHealth(unsigned int health) {
	this->health = health;
}

const Gun& KoratEmpire::getGun() const { //IS this supposed to be an address?
	return gun;
}

void KoratEmpire::setGun(const Gun& gun) {
	this->gun = gun;
}

int KoratEmpire::getSpeed() const {
	return speed;
}

void KoratEmpire::setSpeed(int speed) {
	this->speed = -speed; //set all speed to negative, because the Korat will all be progressing backwards down the lane
}

void KoratEmpire::setType(int type){
    this->koratType = type;
}

bool KoratEmpire::checkDeath()
{
    if (this->health <= 0)
        return true;
    return false;
}
