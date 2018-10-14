#include "Player.h"

Player::Player()
{
    //ctor
}

unsigned int Player::getHealth()
{
    return health;
}

void Player::setHealth(unsigned int val)
{
    health = val;
}

float Player::getSpeed()
{
    return speed;
}

void Player::setSpeed(float val)
{
    speed = val;
}

Gun Player::getGun()
{
    return gun;
}

void Player::setGun(Gun val)
{
    gun = val;
}

Player::~Player()
{
    //dtor
}
