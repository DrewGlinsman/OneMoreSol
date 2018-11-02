
#ifndef INCLUDE_ARCTHROWER_H_
#define INCLUDE_ARCTHROWER_H_

#include "Gun.h"
#include "Bullet.h"

class ArcThrower: public Gun
{
    public:
        ArcThrower();
        virtual ~ArcThrower();
        void shoot();
        void reload();

    private:
        Bullet bullet;
};

#endif
