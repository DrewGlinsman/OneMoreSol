
#ifndef INCLUDE_BFG_H_
#define INCLUDE_BFG_H_

#include "Gun.h"
#include "Bullet.h"

class BFG: public Gun
{
    public:
        BFG();
        virtual ~BFG();
        int getBulletType();
        int getShotsFired();
        void shotsFiredPlusOne();
        void resetShotsFired();
        int getClipSize();
        float getFireRate();
        float getReloadSpeed();

    private:
        int shotsFired = 0;
        int bulletType = 7;
        float fireRate = 0.5;
        int clip = 1;
        float reloadSpeed = 700;
};

#endif
