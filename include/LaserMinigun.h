
#ifndef INCLUDE_LASERMINIGUN_H_
#define INCLUDE_LASERMINIGUN_H_

#include "Gun.h"
#include "Bullet.h"

class LaserMinigun: public Gun
{
    public:
        LaserMinigun();
        virtual ~LaserMinigun();
        void shoot();
        void reload();

    private:
        Bullet bullet;
};

#endif
