
#include "Jackal.h"
#include <iostream>

Jackal::Jackal(int startLane, TextureLoader* loadedTextures){
    lane = 0;

	jackal.setTexture(loadedTextures->textureArray[0]);
	spriteFrame.left = 0;//x
	spriteFrame.top = 768;//y
	spriteFrame.width = 64;
	spriteFrame.height = 64;
	jackal.setTextureRect(spriteFrame);
	jackal.setOrigin(sf::Vector2f(32.f,32.f));
	setLane(startLane);
	jackal.setPosition(1500, lane);
	jackal.setScale(sf::Vector2f(1.2f,1.2f));
}

Jackal::~Jackal() {
	// TODO Auto-generated destructor stub

}

void Jackal::wasShot(int damage)
{
    health = health - damage;
}

int Jackal::getLane()
{
    return lane;
}

std::string Jackal::getName()
{
    return "Jackal";
}

void Jackal::setLane(int givenLane)
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

void Jackal::moveCurrentKorat(float timePassed)
{
        if(jackal.getPosition().x > -100)
        {
            jackal.move(-speed * timePassed, 0);
            if(!((int)jackal.getPosition().x % 10))
                KoratEmpire::incrementRunFrame(&spriteFrame, &jackal);
        }
        else
        {
            survive = true;
        }
}

void Jackal::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(jackal);
}

sf::Sprite Jackal::getKorat()
{
    return jackal;
}

float Jackal::getPositionX()
{
    return jackal.getPosition().x;
}

bool Jackal::checkDeath()
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
			spriteFrame.left = 192;//x
            spriteFrame.top = 768;//y
            spriteFrame.width = 64;
            spriteFrame.height = 64;
            jackal.setTextureRect(spriteFrame);
			return false;
		}
    }
    else
    {
        postDeathClock.restart();
        return false;

    }
}

bool Jackal::checkSurvive()
{
    return survive;
}

int Jackal::getHealth()
{
    return health;
}

int Jackal::getSpeed()
{
    return speed;
}

double Jackal::getFireRate()
{
	return fireRate;
}

void Jackal::setFireRate(double givenFireRate)
{
	fireRate = givenFireRate;
}

bool Jackal::queryToFire()
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
