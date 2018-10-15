// Chris Wolinski SFML Pong

#include "MajorTom.h"

using namespace std;

MajorTom::MajorTom()
{
    majorTom.setSize(sf::Vector2f(50,100));
    //majorTom.setTexture()
    majorTom.setOrigin(majorTom.getSize().x / 2, majorTom.getSize().y / 2);
    majorTom.setPosition(0,100);
    currentHealth = 100;
    //currentGun = PlasmaPistol;

}

void MajorTom::drawTom (sf::RenderWindow& window)
{
    window.draw(majorTom);
}

float MajorTom::getTomPosition()
{
    return majorTom.getPosition().y;
}

void MajorTom::setTomPosition(float positionPassed)
{
    majorTom.setPosition(majorTom.getPosition().x, positionPassed);
}

void MajorTom::moveTomUp(float timePassed)
{
    if (majorTom.getPosition().y == 100)
    {
        // Do not move up - top lane
    }
    else if (majorTom.getPosition().y == 200)
    {
        while(majorTom.getPosition().y != 100)
        {
            majorTom.move(0, timePassed * -400);
        }
    }
    else if (majorTom.getPosition().y == 300)
    {
        while(majorTom.getPosition().y != 200)
        {
            majorTom.move(0, timePassed * -400);
        }
    }
    else if (majorTom.getPosition().y == 400)
    {
        while(majorTom.getPosition().y != 300)
        {
            majorTom.move(0, timePassed * -400);
        }
    }
    else if (majorTom.getPosition().y == 500)
    {
        while(majorTom.getPosition().y != 400)
        {
            majorTom.move(0, timePassed * -400);
        }
    }
}

void MajorTom::moveTomDown(float timePassed)
{
    if (majorTom.getPosition().y == 100)
    {
        while(majorTom.getPosition().y != 200)
        {
            majorTom.move(0, timePassed * 400);
        }
    }
    else if (majorTom.getPosition().y == 200)
    {
        while(majorTom.getPosition().y != 300)
        {
            majorTom.move(0, timePassed * 400);
        }
    }
    else if (majorTom.getPosition().y == 300)
    {
        while(majorTom.getPosition().y != 400)
        {
            majorTom.move(0, timePassed * 400);
        }
    }
    else if (majorTom.getPosition().y == 400)
    {
        while(majorTom.getPosition().y != 500)
        {
            majorTom.move(0, timePassed * 400);
        }
    }
    else if (majorTom.getPosition().y == 500)
    {
        // Do not move down - bottom lane
    }
}

int MajorTom::getHealth()
{
    return currentHealth;
}

void MajorTom::setHealth(int newHealth)
{
    currentHealth = newHealth;
}

Gun MajorTom::getGun()
{
    return currentGun;
}

void MajorTom::setGun(Gun newGun)
{
    currentGun = newGun;
}

