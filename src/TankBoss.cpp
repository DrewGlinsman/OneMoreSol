// Chris Wolinski

#include "TankBoss.h"
#include <iostream>

using namespace std;

TankBoss::TankBoss(TextureLoader* loadedTextures)
{
    //tankBoss.setTexture(loadedTextures->textureArray[0]);
    //tankBoss.setTextureRect(sf::IntRect(640,256,192,192));
    tankBoss.setSize(sf::Vector2f(384.f,384.f));
    tankBoss.setOrigin(sf::Vector2f(384.f/2,384.f/2));
    tankBoss.setScale(1.2f,1.2f);
    tankBoss.setPosition(1800, lane3);
}

void TankBoss::moveBoss(float timePassed)
{
    if(tankBoss.getPosition().x > -100)
    {
        tankBoss.move(-speed * timePassed, 0);
    }
    else
    {
        survive = true;
    }
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

sf::RectangleShape TankBoss::getBoss()
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
