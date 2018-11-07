
#ifndef GUN_H
#define GUN_H

#include<SFML/Graphics.hpp>

class Gun
{
    public:
        Gun();
        virtual ~Gun();

        virtual int getBulletType();
        virtual int getShotsFired();
        virtual void shotsFiredPlusOne();
        virtual void resetShotsFired();
        virtual int getClipSize();
        virtual float getFireRate();
        virtual float getReloadSpeed();

        sf::Image image;

};

#endif
