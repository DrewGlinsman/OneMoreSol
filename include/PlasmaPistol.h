#ifndef PLASMAPISTOL_H
#define PLASMAPISTOL_H

#include <Gun.h>


class PlasmaPistol : public Gun
{
    public:
        PlasmaPistol();
        virtual ~PlasmaPistol();
        void Shoot();
        void Reload();

    protected:

    private:

};

#endif // PLASMAPISTOL_H

