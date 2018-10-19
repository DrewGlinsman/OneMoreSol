// Chris Wolinski SFML Pong

#include "MajorTom.h"

using namespace std;

MajorTom::MajorTom()
{
    majorTom.setSize(sf::Vector2f(50,100));
    //majorTom.setTexture()
    majorTom.setOrigin(majorTom.getSize().x / 2, majorTom.getSize().y / 2);
    majorTom.setPosition(156,508);
    setHealth(100);
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
        if (majorTom.getPosition().y < 422 && majorTom.getPosition().y > 335)
        {
            if(majorTom.getPosition().y > 335 && majorTom.getPosition().y < 341)
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
            if(majorTom.getPosition().y > 422 && majorTom.getPosition().y < 428)
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
            if(majorTom.getPosition().y > 508 && majorTom.getPosition().y < 514)
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
            if(majorTom.getPosition().y > 594 && majorTom.getPosition().y < 600)
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

            if(majorTom.getPosition().y < 422 && majorTom.getPosition().y > 416)
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
            if(majorTom.getPosition().y < 508 && majorTom.getPosition().y > 502)
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
            if(majorTom.getPosition().y < 594 && majorTom.getPosition().y > 588)
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
            if(majorTom.getPosition().y < 680 && majorTom.getPosition().y > 673)
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
    }
}
/*
void MajorTom::moveTomUp(float timePassed)
{
    if (majorTom.getPosition().y > 334 && majorTom.getPosition().y < 346)
    {
        // Do not move up - top lane
    }
    else if (majorTom.getPosition().y > 421 && majorTom.getPosition().y < 423)
    {
        while(majorTom.getPosition().y > 335)
        {
            majorTom.move(timePassed * .05, timePassed * -.1);
        }
        setTomPosition(335);
    }
    else if (majorTom.getPosition().y > 507 && majorTom.getPosition().y < 509)
    {
        while(majorTom.getPosition().y > 422)
        {
            majorTom.move(timePassed * .05, timePassed * -.1);
        }
        setTomPosition(422);
    }
    else if (majorTom.getPosition().y > 593 && majorTom.getPosition().y < 595)
    {
        while(majorTom.getPosition().y > 508)
        {
            majorTom.move(timePassed * .05, timePassed * -.1);
        }
        setTomPosition(508);
    }
    else if (majorTom.getPosition().y > 679 && majorTom.getPosition().y < 681)
    {
        while(majorTom.getPosition().y > 594)
        {
            majorTom.move(timePassed * .05, timePassed * -.1);
        }
        setTomPosition(594);
    }
}

void MajorTom::moveTomDown(float timePassed)
{
    if (majorTom.getPosition().y > 334 && majorTom.getPosition().y < 336)
    {
        while(majorTom.getPosition().y < 422)
        {
            majorTom.move(timePassed * -.05, timePassed * .1);
        }
        setTomPosition(422);
    }
    else if (majorTom.getPosition().y > 421 && majorTom.getPosition().y < 423)
    {
        while(majorTom.getPosition().y < 508)
        {
            majorTom.move(timePassed * -.05, timePassed * .1);
        }
        setTomPosition(508);
    }
    else if (majorTom.getPosition().y > 507 && majorTom.getPosition().y < 509)
    {
        while(majorTom.getPosition().y < 594)
        {
            majorTom.move(timePassed * -.05, timePassed * .1);
        }
        setTomPosition(594);
    }
    else if (majorTom.getPosition().y > 593 && majorTom.getPosition().y < 595)
    {
        while(majorTom.getPosition().y < 680)
        {
            majorTom.move(timePassed * -.05, timePassed * .1);
        }
        setTomPosition(680);
    }
    else if (majorTom.getPosition().y > 679 && majorTom.getPosition().y < 681)
    {
        // Do not move down - bottom lane
    }
}
*/

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

