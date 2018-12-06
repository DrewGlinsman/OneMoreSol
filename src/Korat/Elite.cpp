
#include "Elite.h"
#include <iostream>

Elite::Elite(int startLane, TextureLoader* loadedTextures){

    lane = 0;

	elite.setTexture(loadedTextures->textureArray[0]);
	spriteFrame.left = 0;//x
	spriteFrame.top = 512;//y
	spriteFrame.width = 64;
	spriteFrame.height = 64;
	elite.setTextureRect(spriteFrame);
	elite.setOrigin(sf::Vector2f(32.f, 32.f));
	setLane(startLane);
	elite.setPosition(1500, lane);
	elite.setScale(sf::Vector2f(1.2f,1.2f));

}

Elite::~Elite() {
	// TODO Auto-generated destructor stub

}

void Elite::wasShot(int damage)
{
    health = health - damage;
}

int Elite::getLane()
{
    return lane;
}

std::string Elite::getName()
{
    return "Elite";
}

void Elite::setLane(int givenLane)
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

void Elite::moveCurrentKorat(float timePassed)
{
        if(elite.getPosition().x > -100)
        {
            elite.move(-speed * timePassed, 0);
            if(!((int)elite.getPosition().x % 10))
                KoratEmpire::incrementRunFrame(&spriteFrame, &elite);
        }
        else
        {
            survive = true;
        }
}

void Elite::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(elite);
}

sf::Sprite Elite::getKorat()
{
    return elite;
}

float Elite::getPositionX()
{
    return elite.getPosition().x;
}

bool Elite::checkDeath()
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
            spriteFrame.top = 512;//y
            spriteFrame.width = 64;
            spriteFrame.height = 64;
            elite.setTextureRect(spriteFrame);
			return false;
		}
    }
    else
    {
        postDeathClock.restart();
        return false;

    }
}

bool Elite::checkSurvive()
{
    return survive;
}

int Elite::getHealth()
{
    return health;
}

int Elite::getSpeed()
{
    return speed;
}

double Elite::getFireRate()
{
	return fireRate;
}

void Elite::setFireRate(double givenFireRate)
{
	fireRate = givenFireRate;
}

bool Elite::queryToFire()
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

