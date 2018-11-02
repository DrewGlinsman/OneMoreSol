
#ifndef INCLUDE_PLASMASHOTGUN_H_
#define INCLUDE_PLASMASHOTGUN_H_

#include "Gun.h"
#include "Bullet.h"

class PlasmaShotgun: public Gun
{
    public:
        PlasmaShotgun();
        virtual ~PlasmaShotgun();
        void shoot();
        void reload();

    private:
        Bullet bullet;
};

#endif
