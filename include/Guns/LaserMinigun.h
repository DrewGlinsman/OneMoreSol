
#ifndef INCLUDE_LASERMINIGUN_H_
#define INCLUDE_LASERMINIGUN_H_

#include "Gun.h"
#include "Bullet.h"

class LaserMinigun: public Gun
{
    public:
        LaserMinigun();
        virtual ~LaserMinigun();
        int getBulletType();
        int getShotsFired();
        void shotsFiredPlusOne();
        void resetShotsFired();
        int getClipSize();
        float getFireRate();
        float getReloadSpeed();

    private:
        int shotsFired = 0;
        int bulletType = 4;
        float fireRate = 0.1;
        int clip = 10;
        float reloadSpeed = 5;
};

#endif
