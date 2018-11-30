// Chris Wolinski

#include "TankBoss.h"
#include <iostream>

using namespace std;

TankBoss::TankBoss(TextureLoader* loadedTextures)
{
    tankBoss.setTexture(loadedTextures->textureArray[0]);
    spriteFrame.left = 512;//x
	spriteFrame.top = 448;//y
	spriteFrame.width = 320;
	spriteFrame.height = 320;
    tankBoss.setTextureRect(spriteFrame);
    //tankBoss.setSize(sf::Vector2f(384.f,384.f));
    //tankBoss.setOrigin(sf::Vector2f(384.f/2,384.f/2));
    tankBoss.setOrigin(sf::Vector2f(160.f,160.f));
    tankBoss.setScale(1.2f,1.2f);
    tankBoss.setPosition(1800, lane3);
}

void TankBoss::moveBoss(float timePassed)
{
    if(tankBoss.getPosition().x > -100)
    {
        tankBoss.move(-speed * timePassed, 0);
        if(!((int)tankBoss.getPosition().x % 3))//slows down the switching of frames
        {
            incrementRunFrameBoss(&spriteFrame, &tankBoss);
        }
    }
    else
    {
        survive = true;
    }
}

void TankBoss::incrementRunFrameBoss(sf::IntRect* sF, sf::Sprite* baddie)
{
    //start with the upper left coordinate, add the sprite width to it
    //to move to the next frame. To loop, make circular arith with mod
    // 3*192 is 576, as mod circles back to 0, add the initial value 832.
    //should 832 be added at every increment? no
    sF->left = ((sF->left +320)%1792); //+832
    if(sF->left == 0) {sF->left += 512;}
    baddie->setTextureRect(*sF);
}

bool TankBoss::checkDeath()
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

bool TankBoss::checkSurvive()
{
    return survive;
}

float TankBoss::getPositionX()
{
    return tankBoss.getPosition().x - 220;
}

sf::Sprite TankBoss::getBoss()
{
    return tankBoss;
}

void TankBoss::wasShot(int damage)
{
    health = health - damage;
}

int TankBoss::getSpeed()
{
    return speed;
}

bool TankBoss::queryToFire()
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

int TankBoss::decideFiringLane()
{
    int lane = firingLane[index];
    index++;
    return lane;
}

void TankBoss::drawBoss(sf::RenderWindow& window)
{
    window.draw(tankBoss);
}
