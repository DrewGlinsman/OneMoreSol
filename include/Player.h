#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Gun.h"

class Player
{
public:
    Player();
    virtual ~Player();

    unsigned int getHealth()
    {
        return health;
    }
    void setHealth(unsigned int val)
    {
        health = val;
    }
    float getSpeed()
    {
        return speed;
    }
    void setSpeed(float val)
    {
        speed = val;
    }
    Gun getGun()
    {
        return gun;
    }
    void setGun(Gun val)
    {
        gun = val;
    }

protected:

private:
    sf::Sprite playerImage;
    unsigned int health;
    float speed;
    Gun gun;
};

#endif // PLAYER_H
