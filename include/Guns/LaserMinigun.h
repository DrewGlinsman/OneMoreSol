
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
        void shoot();
        void reload();

    private:
        int shotsFired = 0;
        int bulletType = 4;
        float fireRate = 0.5;
        int clip = 10;
        int damage = 5;
        int dmgMultiplier = 2;
        float reloadSpeed = 1.5;
};

#endif
