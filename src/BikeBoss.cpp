// Chris Wolinski

#include "BikeBoss.h"
#include <iostream>

using namespace std;

BikeBoss::BikeBoss(TextureLoader* loadedTextures)
{
	bikeBoss.setTexture(loadedTextures->mtSpriteSheet);
    bikeBoss.setTextureRect(sf::IntRect(832,256,192,192));
    bikeBoss.setOrigin(sf::Vector2f(96.f,96.f));
    bikeBoss.setScale(1.2f,1.2f);
	bikeBoss.setPosition(1500, lane3);
}

float BikeBoss::getBossPosition()
{
    return bikeBoss.getPosition().y;
}

void BikeBoss::setBossPosition(float positionPassed)
{
    bikeBoss.setPosition(bikeBoss.getPosition().x, positionPassed);
}

void BikeBoss::initBossUp()
{
    if (getBossPosition() == lane2)
    {

    }
    else if (getBossPosition() == lane3)
    {
        setBossPosition(lane3 - 5);
    }
    else if (getBossPosition() == lane4)
    {
        setBossPosition(lane4 - 5);
    }
}

bool BikeBoss::moveBossUp(float timePassed)
{
        std::cout << getBossPosition() << std::endl;
    if (getBossPosition() > lane2)
    {
        if (getBossPosition() < lane3 - 4 | getBossPosition() > lane3 + 4)
        {
            bikeBoss.move(0, -speed * timePassed);
            std::cout << "moving up" << std::endl;
            return false;
        }
        else
        {
            setBossPosition(lane3);
            return true;
        }
    }
    else
    {
        setBossPosition(lane2);
        return true;
    }
}

void BikeBoss::initBossDown()
{
    if (getBossPosition() == lane2)
    {
       setBossPosition(lane2 + 5);
    }
    else if (getBossPosition() == lane3)
    {
       setBossPosition(lane3 + 5);
    }
    else if (getBossPosition() == lane4)
    {

    }
}

bool BikeBoss::moveBossDown(float timePassed)
{
    if (getBossPosition() < lane4)
    {
        if (getBossPosition() < lane3 - 4 | getBossPosition() > lane3 + 4)
        {
            bikeBoss.move(0, speed * timePassed);
            return false;
        }
        else
        {
            setBossPosition(lane3);
            return true;
        }
    }
    else
    {
        setBossPosition(lane4);
        return true;
    }
}

void BikeBoss::moveBoss(float timePassed)
{
    if(bikeBoss.getPosition().x > -100)
    {
        bikeBoss.move(-speed * timePassed, 0);
    }
    else
    {
        survive = true;
    }
}

bool BikeBoss::checkDeath()
{
    if (health <= 0)
    {
		postDeathTime = postDeathClock.getElapsedTime().asSeconds();
		if (postDeathTime >= .5)
		{
			postDeathClock.restart();
			return true;
		}
		else
        {
			speed = 0;
		}
    }
    else
    {
        postDeathClock.restart();
        return false;

    }
}

bool BikeBoss::checkSurvive()
{
    return survive;
}

void BikeBoss::drawBoss(sf::RenderWindow& window)
{
    window.draw(bikeBoss);
}
