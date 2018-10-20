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
	int getLane();

    void setType(int type);

private:
	unsigned int health;
	float speed;
	Gun gun;
    int koratType;
	int lane;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;
};

#endif /* INCLUDE_KORATEMPIRE_H_ */
