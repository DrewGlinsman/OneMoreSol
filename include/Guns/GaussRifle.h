

#ifndef INCLUDE_GAUSSRIFLE_H_
#define INCLUDE_GAUSSRIFLE_H_

#include "Gun.h"
#include "Bullet.h"

class GaussRifle: public Gun
{
    public:
        GaussRifle();
        virtual ~GaussRifle();
        int getBulletType();
        int getShotsFired();
        void shotsFiredPlusOne();
        void resetShotsFired();
        int getClipSize();
        float getFireRate();
        float getReloadSpeed();

    private:
        int shotsFired = 0;
        int bulletType = 6;
        float fireRate = 1.0;
        int clip = 3;

        float reloadSpeed = 4;
};

#endif
