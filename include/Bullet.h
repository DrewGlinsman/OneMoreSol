#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet
{
    public:
        Bullet();
        virtual ~Bullet();

        float getVelocity();
        void setVelocity(float);
        float getPositionX();
        float getPositionY();
        float setPosition(sf::Vector2f newPos);

        virtual doDamage();

    protected:

    private:
        //damage
        float damage;

        //speed
        float velocity;

        //location
        float positionX;
        float positionY;
};

#endif // BULLET_H
