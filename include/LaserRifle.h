
#ifndef INCLUDE_LASERRIFLE_H_
#define INCLUDE_LASERRIFLE_H_

#include "Gun.h"
#include "Bullet.h"

class LaserRifle: public Gun
{
public:
	LaserRifle();
	virtual ~LaserRifle();
    void shoot();
    void reload();

private:
    Bullet bullet;
};

#endif
