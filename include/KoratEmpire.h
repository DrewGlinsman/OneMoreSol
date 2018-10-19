/*
 * KoratEmpire.h
 *
 *  Created on: Oct 14, 2018
 *      Author: jabowden
 */

#ifndef INCLUDE_KORATEMPIRE_H_
#define INCLUDE_KORATEMPIRE_H_

#include <SFML/Graphics.hpp>
#include "Gun.h"

class KoratEmpire {
public:
	KoratEmpire();
	virtual ~KoratEmpire();

	unsigned int getHealth() const;
	void setHealth(unsigned int health);

	const Gun& getGun() const;
	void setGun(const Gun& gun);

	int getSpeed() const;
	void setSpeed(int speed);

	bool checkDeath();

	void setLane(int lane);
	float getLane();


private:
	unsigned int health;
	float speed;
	Gun gun;

	float lane;

    float lane1 = 335;
    float lane2 = 422;
    float lane3 = 508;
    float lane4 = 594;
    float lane5 = 680;
};

#endif /* INCLUDE_KORATEMPIRE_H_ */
