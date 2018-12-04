
#ifndef INCLUDE_PLASMASHOTGUN_H_
#define INCLUDE_PLASMASHOTGUN_H_

#include "Gun.h"
#include "Bullet.h"

class PlasmaShotgun: public Gun
{
    public:
        PlasmaShotgun();
        virtual ~PlasmaShotgun();
        int getBulletType();
        int getShotsFired();
        void shotsFiredPlusOne();
        void resetShotsFired();
        int getClipSize();
        float getFireRate();
        float getReloadSpeed();

    private:
        int shotsFired = 0;
        int bulletType = 2;
        float fireRate = 1;
        int clip = 6;
        float reloadSpeed = 1.5;
};

#endif
