
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Gun.h"

class Player
{
public:
    Player();
    virtual ~Player();

    unsigned int getHealth();
    void setHealth(unsigned int val);
    float getSpeed();
    void setSpeed(float val);
    Gun getGun();
    void setGun(Gun val);

protected:

private:
    sf::Sprite playerImage;
    unsigned int health;
    float speed;
    Gun gun;
};

#endif
