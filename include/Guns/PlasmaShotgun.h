
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
        void shoot();
        void reload();

    private:
        int shotsFired = 0;
        int bulletType = 2;
        float fireRate = 0.5;
        int clip = 10;
        int damage = 5;
        int dmgMultiplier = 2;
        float reloadSpeed = 1.5;
};

#endif
