
#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet
{
    public:
        Bullet();
        virtual ~Bullet();

       virtual float getVelocity();
       virtual void setVelocity(float);
       virtual float getPositionX();
       virtual float getPositionY();
       virtual float setPosition(sf::Vector2f newPos);
       virtual int getDamage();
       virtual void moveCurrentBullet(float timePassed);
       virtual void drawCurrentBullet(sf::RenderWindow& window);

       virtual bool getOutOfBounds();
       virtual sf::RectangleShape getBullet();

    protected:

    private:
        //damage
        int damage;

        //speed
        float velocity;

        //location
        float positionX;
        float positionY;
        bool outOfBounds;


};

#endif
