/*
 * KoratEmpire.h
 *
 *  Created on: Oct 14, 2018
 *      Author: jabowden
 */

#ifndef INCLUDE_KORATEMPIRE_H_
#define INCLUDE_KORATEMPIRE_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Gun.h"

class KoratEmpire {
public:
	KoratEmpire();
	virtual ~KoratEmpire();

	virtual bool checkDeath();

	virtual void setLane(int givenLane);
	virtual int getLane();

	virtual void moveCurrentKorat(float timepassed);

	virtual void drawCurrentKorat(sf::RenderWindow& window);

    int lane;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;


private:
	unsigned int health;
	float speed;
	Gun gun;
    int koratType;

};

#endif /* INCLUDE_KORATEMPIRE_H_ */
