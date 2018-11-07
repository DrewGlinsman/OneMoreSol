
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
        int getShotsFired();
        void shotsFiredPlusOne();
        void resetShotsFired();
        int getClipSize();
        float getFireRate();
        float getReloadSpeed();

    private:
        int shotsFired = 0;
        int bulletType = 3;
        float fireRate = 0.1;
        int clip = 25;
        float reloadSpeed = 1.5;
};

#endif
