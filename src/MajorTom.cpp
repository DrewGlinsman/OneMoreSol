// Chris Wolinski

#include "MajorTom.h"
#include <iostream>

using namespace std;

MajorTom::MajorTom(TextureLoader* loadedTextures)
{
    setGun(1);

    majorTom.setTexture(loadedTextures->textureArray[0]);
    majorTom.setTextureRect(sf::IntRect(0,0,64,64));
    majorTom.setOrigin(sf::Vector2f(32.f, 32.f));
    majorTom.setPosition(156,508);
    majorTom.setScale(sf::Vector2f(1.2f,1.2f));
    setHealth(100);
    setSurvivors(20);
}

void MajorTom::drawTom (sf::RenderWindow& window)
{
    window.draw(majorTom);
}

float MajorTom::getTomPosition()
{
    return majorTom.getPosition().y;
}

float MajorTom::getTomPositionX()
{
    return majorTom.getPosition().x;
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

sf::Sprite MajorTom::getTom()
{
    return majorTom;
}

void MajorTom::wasShot(int damage)
{
    setHealth(getHealth() - damage);

}

int MajorTom::getHealth()
{
    return currentHealth;
}

void MajorTom::setHealth(int newHealth)
{
    currentHealth = newHealth;
}

int MajorTom::getGun()
{
    return currentGun;
}

void MajorTom::setGun(int gunNumber)
{
    switch(gunNumber)
    {
        case 1:
            currentGun = 1;
            break;
        case 2:
            currentGun = 2;
            break;
        case 3:
            currentGun = 3;
            break;
        case 4:
            currentGun = 4;
            break;
        case 5:
            currentGun = 5;
            break;
        case 6:
            currentGun = 6;
            break;
        case 7:
            currentGun = 7;
            break;
        default:
            currentGun = 1;
            break;

    }
}

int MajorTom::getSurvivors()
{
    return survivorCnt;
}

void MajorTom::setSurvivors(int num)
{
    survivorCnt = num;
}

bool MajorTom::checkDeath()
{
    if (currentHealth <= 0)
        return true;
    return false;
}

