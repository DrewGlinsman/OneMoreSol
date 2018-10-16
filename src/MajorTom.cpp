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
    if (majorTom.getPosition().y > 330 && majorTom.getPosition().y < 340)
    {
        // Do not move up - top lane
    }
    else if (majorTom.getPosition().y > 417 && majorTom.getPosition().y < 427)
    {
        while(majorTom.getPosition().y > 335)
        {
            majorTom.move(0, timePassed * -400);
        }
    }
    else if (majorTom.getPosition().y > 503 && majorTom.getPosition().y < 518)
    {
        while(majorTom.getPosition().y > 422)
        {
            majorTom.move(0, timePassed * -400);
        }
    }
    else if (majorTom.getPosition().y > 589 && majorTom.getPosition().y < 594)
    {
        while(majorTom.getPosition().y > 508)
        {
            majorTom.move(0, timePassed * -400);
        }
    }
    else if (majorTom.getPosition().y > 675 && majorTom.getPosition().y < 685)
    {
        while(majorTom.getPosition().y > 594)
        {
            majorTom.move(0, timePassed * -400);
        }
    }
}

void MajorTom::moveTomDown(float timePassed)
{
    if (majorTom.getPosition().y > 330 && majorTom.getPosition().y < 340)
    {
        while(majorTom.getPosition().y < 422)
        {
            majorTom.move(0, timePassed * 400);
        }
    }
    else if (majorTom.getPosition().y > 417 && majorTom.getPosition().y < 427)
    {
        while(majorTom.getPosition().y < 508)
        {
            majorTom.move(0, timePassed * 400);
        }
    }
    else if (majorTom.getPosition().y > 503 && majorTom.getPosition().y < 518)
    {
        while(majorTom.getPosition().y < 594)
        {
            majorTom.move(0, timePassed * 400);
        }
    }
    else if (majorTom.getPosition().y > 589 && majorTom.getPosition().y < 594)
    {
        while(majorTom.getPosition().y < 680)
        {
            majorTom.move(0, timePassed * 400);
        }
    }
    else if (majorTom.getPosition().y > 675 && majorTom.getPosition().y < 685)
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

bool MajorTom::checkDeath()
{
    if (currentHealth <= 0)
        return true;
    return false;
}

