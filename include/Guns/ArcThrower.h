
#ifndef INCLUDE_ARCTHROWER_H_
#define INCLUDE_ARCTHROWER_H_

#include "Gun.h"
#include "Bullet.h"

class ArcThrower: public Gun
{
    public:
        ArcThrower();
        virtual ~ArcThrower();
        int getBulletType();
        int getShotsFired();
        void shotsFiredPlusOne();
        void resetShotsFired();
        int getClipSize();
        float getFireRate();
        float getReloadSpeed();

    private:
        int shotsFired = 0;
        int bulletType = 5;
        float fireRate = 0.5;
        int clip = 10;
        float reloadSpeed = 1.5;
};

#endif
