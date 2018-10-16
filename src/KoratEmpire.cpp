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

void KoratEmpire::setHealth(unsigned int health) {
	this->health = health;
}

const Gun& KoratEmpire::getGun() const { //IS this supposed to be an address?
	return gun;
}

void KoratEmpire::setGun(const Gun& gun) {
	this->gun = gun;
}

float KoratEmpire::getSpeed() const {
	return speed;
}

void KoratEmpire::setSpeed(float speed) {
	this->speed = speed;
}

bool checkDeath()
{
    if (health <= 0)
        return true;
    return false;
}
