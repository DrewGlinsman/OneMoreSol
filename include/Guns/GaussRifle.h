

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
        void shoot();
        void reload();

    private:
        int shotsFired = 0;
        int bulletType = 6;
        float fireRate = 0.5;
        int clip = 10;
        int damage = 5;
        int dmgMultiplier = 2;
        float reloadSpeed = 1.5;
};

#endif
