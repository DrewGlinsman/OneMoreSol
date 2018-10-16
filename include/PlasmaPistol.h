#ifndef PLASMAPISTOL_H
#define PLASMAPISTOL_H

#include <Gun.h>
#include <Bullet.h>

class PlasmaPistol : public Gun
{
    public:
        PlasmaPistol();
        virtual ~PlasmaPistol();
        void Shoot();
        void Reload();

    protected:

    private:
        Bullet bullet;

};

#endif // PLASMAPISTOL_H
