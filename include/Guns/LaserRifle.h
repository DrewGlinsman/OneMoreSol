
#ifndef INCLUDE_LASERRIFLE_H_
#define INCLUDE_LASERRIFLE_H_

#include "Gun.h"
#include "Bullet.h"

class LaserRifle: public Gun
{
public:
	LaserRifle();
	virtual ~LaserRifle();
    int getBulletType();
    void shoot();
    void reload();

private:
        int shotsFired = 0;
        int bulletType = 3;
        float fireRate = 0.5;
        int clip = 10;
        int damage = 5;
        int dmgMultiplier = 2;
        float reloadSpeed = 1.5;
};

#endif
