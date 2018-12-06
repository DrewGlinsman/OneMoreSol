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
	bikeBoss.setPosition(1550, lane3);
	dieBool = false;
}

float BikeBoss::getBossPosition()
{
    return bikeBoss.getPosition().y;
}

float BikeBoss::getPositionX()
{
    return bikeBoss.getPosition().x;
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
            bikeBoss.move(0, -speed * timePassed * 4);
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
            bikeBoss.move(0, speed * timePassed * 4);
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
        if(!((int)bikeBoss.getPosition().x % 7))//slows down the switching of frames
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
    //start with the upper left coordinate, add the sprite width to it
    //to move to the next frame. To loop, make circular arith with mod
    // 3*192 is 576, as mod circles back to 0, add the initial value 832.
    //should 832 be added at every increment? no
    sF->left = ((sF->left +192)%1408); //+832
    if(sF->left == 0) {sF->left += 832;}
    baddie->setTextureRect(*sF);
}

bool BikeBoss::checkDeath()
{
    if (health <= 0)
    {
		postDeathTime = postDeathClock.getElapsedTime().asSeconds();
		if (postDeathTime >= 5)
		{
			postDeathClock.restart();
			return true;
		}
		else
        {
			speed = 0;
			if(!dieBool)
            {
                dieBool = true;
                //death animate
                //align the frame to the explosion
                //alignment is one "frame" away from where it should be to compensate
                //for the first math add of 192 in the modular arith
                spriteFrame.left = 384;//576;//x
                spriteFrame.top = 768;//y
                spriteFrame.width = 192;
                spriteFrame.height = 192;
                bikeBoss.setOrigin(sf::Vector2f(96.f,96.f));
                bikeBoss.setScale(sf::Vector2f(2.f,2.f));
            }

            spriteFrame.left = ((spriteFrame.left + 192)%1344);//adjust for sprite location
            if(spriteFrame.left == 0) {spriteFrame.left += 960;}//put on frame 3 to cycle plosion
            bikeBoss.setTextureRect(spriteFrame);
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

bool BikeBoss::queryToFire()
{
	bool readyToFire = false;
	lastBulletFired = fireBulletClock.getElapsedTime().asSeconds();

    // 0.67415730337
	if(lastBulletFired > 0.33707865168)
	{
	   readyToFire = true;
	   fireBulletClock.restart();
	}

return readyToFire;
}

void BikeBoss::drawBoss(sf::RenderWindow& window)
{
    window.draw(bikeBoss);
}
