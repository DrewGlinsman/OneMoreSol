
#include "Brute.h"
#include <iostream>

Brute::Brute(int startLane, TextureLoader* loadedTextures){
    lane = 0;

	brute.setTexture(loadedTextures->textureArray[0]);
	spriteFrame.left = 0;//x
	spriteFrame.top = 640;//y
	spriteFrame.width = 64;
	spriteFrame.height = 64;
	brute.setTextureRect(spriteFrame);
	brute.setOrigin(sf::Vector2f(32.f,32.f));
	setLane(startLane);
	brute.setPosition(1500, lane);
	brute.setScale(sf::Vector2f(1.2f,1.2f));

}

Brute::~Brute() {
	// TODO Auto-generated destructor stub

}

void Brute::wasShot(int damage)
{
    health = health - damage;
}

int Brute::getLane()
{
    return lane;
}

std::string Brute::getName()
{
    return "Brute";
}

void Brute::setLane(int givenLane)
{
     switch(givenLane)
	{
		case 1:
			lane = lane1;
			break;
		case 2:
			lane = lane2;
			break;
		case 3:
			lane = lane3;
			break;
		case 4:
			lane = lane4;
			break;
		case 5:
			lane = lane5;
			break;
		default:
			lane = lane1;
			break;
	}
}

void Brute::moveCurrentKorat(float timePassed)
{
        if(brute.getPosition().x > -100)
        {
            brute.move(-speed * timePassed, 0);
            if(!((int)brute.getPosition().x % 10))
                KoratEmpire::incrementRunFrame(&spriteFrame, &brute);
        }
        else
        {
            survive = true;
        }
}

void Brute::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(brute);
}

sf::Sprite Brute::getKorat()
{
    return brute;
}

float Brute::getPositionX()
{
    return brute.getPosition().x;
}

bool Brute::checkDeath()
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
			if (koratDeathSoundPlayed == false)
			{
				postDeathClock.restart();
				koratDeathSoundPlayed = true;
			}
			return false;
		}
    }
    else
    {
        postDeathClock.restart();
        return false;

    }
}

bool Brute::checkSurvive()
{
    return survive;
}

int Brute::getHealth()
{
    return health;
}

int Brute::getSpeed()
{
    return speed;
}

double Brute::getFireRate()
{
	return fireRate;
}

void Brute::setFireRate(double givenFireRate)
{
	fireRate = givenFireRate;
}

bool Brute::queryToFire()
{
	bool readyToFire = false;
	lastBulletFired = fireBulletClock.getElapsedTime().asSeconds();

	if(lastBulletFired > getFireRate())
	{
	   readyToFire = true;

	   double randomFireRate = Random() * 3;
	   if(randomFireRate > 1 && randomFireRate < 2)
		  setFireRate(2);
	   else if(randomFireRate > 2)
		  setFireRate(3);
	   else
		   setFireRate(1);
	   setFireRate(randomFireRate * 2);
	   fireBulletClock.restart();
	}


	return readyToFire;
}
