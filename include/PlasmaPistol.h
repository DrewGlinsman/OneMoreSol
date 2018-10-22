
#ifndef PLASMAPISTOL_H
#define PLASMAPISTOL_H

#include "Gun.h"
#include "Bullet.h"

class PlasmaPistol : public Gun
{
    public:
        PlasmaPistol();
        virtual ~PlasmaPistol();
        void shoot();
        void reload();

    protected:

    private:
        Bullet bullet;

};

#endif
