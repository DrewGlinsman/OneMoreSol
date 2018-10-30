

#ifndef INCLUDE_GAUSSRIFLE_H_
#define INCLUDE_GAUSSRIFLE_H_

#include "Gun.h"
#include "Bullet.h"

class GaussRifle: public Gun
{
    public:
        GaussRifle();
        virtual ~GaussRifle();
        void shoot();
        void reload();

    private:
        Bullet bullet;
};

#endif
