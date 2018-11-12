// Chris Wolinski

#include "BikeBoss.h"
#include <iostream>

using namespace std;

BikeBoss::BikeBoss(TextureLoader* loadedTextures)
{
	bikeBoss.setTexture(loadedTextures->textureArray[0]);
	spriteFrame.left = 832;//x
	spriteFrame.top = 256;//y
	spriteFrame.width = 192;
	spriteFrame.height = 192;
    bikeBoss.setTextureRect(spriteFrame);
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
        setBossPosition(lane3 - 2);
    }
    else if (getBossPosition() == lane4)
    {
        setBossPosition(lane4 - 2);
    }
}

bool BikeBoss::moveBossUp(float timePassed)
{
    if (getBossPosition() > lane2)
    {
        if (getBossPosition() < lane3 - 1 | getBossPosition() > lane3 + 1)
        {
            bikeBoss.move(0, -speed * timePassed * 2);
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
       setBossPosition(lane2 + 2);
    }
    else if (getBossPosition() == lane3)
    {
       setBossPosition(lane3 + 2);
    }
    else if (getBossPosition() == lane4)
    {

    }
}

bool BikeBoss::moveBossDown(float timePassed)
{
    if (getBossPosition() < lane4)
    {
        if (getBossPosition() < lane3 - 1 | getBossPosition() > lane3 + 1)
        {
            bikeBoss.move(0, speed * timePassed * 2);
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
        if(!((int)bikeBoss.getPosition().x % 5))
        {
            incrementRunFrameBoss(&spriteFrame, &bikeBoss);
        }
    }
    else
    {
        survive = true;
    }
}

void BikeBoss::incrementRunFrameBoss(sf::IntRect* sF, sf::Sprite* baddie)
{
    sF->left = ((sF->left+192)%576)+832;
    baddie->setTextureRect(*sF);
}

bool BikeBoss::checkDeath()
{
    if (health <= 0)
    {
		postDeathTime = postDeathClock.getElapsedTime().asSeconds();
		cout << postDeathTime << endl;
		if (postDeathTime >= 3)
		{
			postDeathClock.restart();
			return true;
		}
		else
        {
			speed = 0;
			return false;
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

sf::Sprite BikeBoss::getBoss()
{
    return bikeBoss;
}

void BikeBoss::wasShot(int damage)
{
    health = health - damage;
}

int BikeBoss::getSpeed()
{
    return speed;
}


void BikeBoss::drawBoss(sf::RenderWindow& window)
{
    window.draw(bikeBoss);
}
