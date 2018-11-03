
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
        void shoot();
        void reload();

    private:
        int shotsFired = 0;
        int bulletType = 7;
        float fireRate = 0.5;
        int clip = 10;
        int damage = 5;
        int dmgMultiplier = 2;
        float reloadSpeed = 1.5;
};

#endif
