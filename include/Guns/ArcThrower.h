
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
        void shoot();
        void reload();

    private:
        int shotsFired = 0;
        int bulletType = 5;
        float fireRate = 0.5;
        int clip = 10;
        int damage = 5;
        int dmgMultiplier = 2;
        float reloadSpeed = 1.5;
};

#endif
