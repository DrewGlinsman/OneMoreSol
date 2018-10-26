
#ifndef INCLUDE_GAUSBULLET_H_
#define INCLUDE_GAUSSBULLET_H_

#include "Bullet.h"

class GaussBullet: public Bullet {
public:
	GaussBullet();
	virtual ~GaussBullet();

	float getPositionX();
};

#endif
