// Chris Wolinski SFML Pong

#include "MajorTom.h"
#include <iostream>

using namespace std;

MajorTom::MajorTom(TextureLoader* loadedTextures)
{
    setGun(1);

    majorTom.setTexture(loadedTextures->mtSpriteSheet);
    majorTom.setTextureRect(sf::IntRect(0,0,64,64));
    majorTom.setOrigin(sf::Vector2f(32.f, 32.f));
    majorTom.setPosition(156,508);
    majorTom.setScale(sf::Vector2f(1.2f,1.2f));
    setHealth(100);

}

void MajorTom::drawTom (sf::RenderWindow& window)
{
    window.draw(majorTom);
}

float MajorTom::getTomPosition()
{
    return majorTom.getPosition().y;
}

void MajorTom::setTomPositionX(float positionPassed)
{
    majorTom.setPosition(positionPassed ,majorTom.getPosition().y);
}

void MajorTom::setTomPositionY(float positionPassed)
{
    majorTom.setPosition(majorTom.getPosition().x, positionPassed);
}

bool MajorTom::initMove(float timePassed, string direction)
{
    if(direction == "Up")
    {
        if(majorTom.getPosition().y == 335)
        {
            //At Top
            return false;
        }
        else if(majorTom.getPosition().y == 422)
        {
            setTomPositionY(421);
            return keepMoving(timePassed, direction);
        }
        else if(majorTom.getPosition().y == 508)
        {
            setTomPositionY(507);
            return keepMoving(timePassed, direction);
        }
        else if(majorTom.getPosition().y == 594)
        {
            setTomPositionY(593);
            return keepMoving(timePassed, direction);
        }
        else if(majorTom.getPosition().y == 680)
        {
            setTomPositionY(679);
            return keepMoving(timePassed, direction);
        }
        else
        {
            return false;
        }
    }
    else if(direction == "Down")
    {
        if(majorTom.getPosition().y == 335)
        {
            setTomPositionY(336);
            return keepMoving(timePassed, direction);
        }
        else if(majorTom.getPosition().y == 422)
        {
            setTomPositionY(423);
            return keepMoving(timePassed, direction);
        }
        else if(majorTom.getPosition().y == 508)
        {
            setTomPositionY(509);
            return keepMoving(timePassed, direction);
        }
        else if(majorTom.getPosition().y == 594)
        {
            setTomPositionY(595);
            return keepMoving(timePassed, direction);
        }
        else if(majorTom.getPosition().y == 680)
        {
            //At Bottom
            return false;
        }
        else
        {
            return false;
        }
    }
    else return false;
}

bool MajorTom::keepMoving(float timePassed, string direction)
{
    if(direction == "Up")
    {
        if (majorTom.getPosition().y < 335)
        {
            setTomPositionX(238);
            setTomPositionY(335);
            return false;
        }
        else if (majorTom.getPosition().y < 422 && majorTom.getPosition().y > 335)
        {
            if(majorTom.getPosition().y > 335 && majorTom.getPosition().y < 345)
            {
                setTomPositionX(238);
                setTomPositionY(335);
                return false;
            }
            else
            {
                majorTom.move(timePassed * 250, timePassed * -500);
                return true;
            }
        }
        else if (majorTom.getPosition().y < 508 && majorTom.getPosition().y > 422)
        {
            if(majorTom.getPosition().y > 422 && majorTom.getPosition().y < 432)
            {
                setTomPositionX(197);
                setTomPositionY(422);
                return false;
            }
            else
            {
                majorTom.move(timePassed * 250, timePassed * -500);
                return true;
            }
        }
        else if (majorTom.getPosition().y < 594 && majorTom.getPosition().y > 508)
        {
            if(majorTom.getPosition().y > 508 && majorTom.getPosition().y < 518)
            {
                setTomPositionX(155);
                setTomPositionY(508);
                return false;
            }
            else
            {
                majorTom.move(timePassed * 250, timePassed * -500);
                return true;
            }
        }
        else if (majorTom.getPosition().y < 680 && majorTom.getPosition().y > 594)
        {
            if(majorTom.getPosition().y > 594 && majorTom.getPosition().y < 604)
            {
                setTomPositionX(114);
                setTomPositionY(594);
                return false;
            }
            else
            {
                majorTom.move(timePassed * 250, timePassed * -500);
                return true;
            }
        }
    }
    else if(direction == "Down")
    {
        if (majorTom.getPosition().y < 422 && majorTom.getPosition().y > 335)
        {

            if(majorTom.getPosition().y < 422 && majorTom.getPosition().y > 412)
            {
                setTomPositionX(197);
                setTomPositionY(422);
                return false;
            }
            else
            {
                majorTom.move(timePassed * -250, timePassed * 500);
                return true;
            }
        }
        else if (majorTom.getPosition().y < 508 && majorTom.getPosition().y > 422)
        {
            if(majorTom.getPosition().y < 508 && majorTom.getPosition().y > 498)
            {
                setTomPositionX(155);
                setTomPositionY(508);
                return false;
            }
            else
            {
                majorTom.move(timePassed * -250, timePassed * 500);
                return true;
            }
        }
        else if (majorTom.getPosition().y < 594 && majorTom.getPosition().y > 508)
        {
            if(majorTom.getPosition().y < 594 && majorTom.getPosition().y > 584)
            {
                setTomPositionX(114);
                setTomPositionY(594);
                return false;
            }
            else
            {
                majorTom.move(timePassed * -250, timePassed * 500);
                return true;
            }
        }
        else if (majorTom.getPosition().y < 680 && majorTom.getPosition().y > 594)
        {
            if(majorTom.getPosition().y < 680 && majorTom.getPosition().y > 670)
            {
                setTomPositionX(72);
                setTomPositionY(680);
                return false;
            }
            else
            {
                majorTom.move(timePassed * -250, timePassed * 500);
                return true;
            }
        }
        else if (majorTom.getPosition().y > 680)
            {
                setTomPositionX(72);
                setTomPositionY(680);
                return false;
            }
        }
}

void MajorTom::shoot(float timePassed)
{
    currentGun.shoot(timePassed);
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

void MajorTom::setGun(int gunNumber)
{
    switch(gunNumber)
    {
        case 1:
            currentGun = *pistol;
            break;
        case 2:
            currentGun = *shotgun;
            break;
        case 3:
            currentGun = *rifle;
            break;
        case 4:
            currentGun = *minigun;
            break;
        case 5:
            currentGun = *thrower;
            break;
        case 6:
            currentGun = *sniper;
            break;
        case 7:
            currentGun = *bigFunGun;
            break;
        default:
            currentGun = *pistol;
            break;

    }
}

bool MajorTom::checkDeath()
{
    if (currentHealth <= 0)
        return true;
    return false;
}

