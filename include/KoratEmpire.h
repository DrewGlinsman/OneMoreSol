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

	float getSpeed() const;
	void setSpeed(float speed);

private:
	unsigned int health;
	float speed;
	Gun gun;
};

#endif /* INCLUDE_KORATEMPIRE_H_ */
