
#ifndef INCLUDE_BFG_H_
#define INCLUDE_BFG_H_

#include "Gun.h"
#include "Bullet.h"

class BFG: public Gun
{
    public:
        BFG();
        virtual ~BFG();
        void shoot();
        void reload();

    private:
        Bullet bullet;
};

#endif
