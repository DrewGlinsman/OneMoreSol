
#include "Hunter.h"
#include <iostream>

Hunter::Hunter(int startLane, TextureLoader* loadedTextures){
    lane = 0;

	hunter.setTexture(loadedTextures->textureArray[0]);
	spriteFrame.left = 0;//x
	spriteFrame.top = 768;//y
	spriteFrame.width = 64;
	spriteFrame.height = 64;
	hunter.setTextureRect(spriteFrame);
	hunter.setOrigin(sf::Vector2f(32.f,32.f));
	setLane(startLane);
	hunter.setPosition(1500, lane);
	hunter.setScale(sf::Vector2f(1.2f,1.2f));
}

Hunter::~Hunter() {
	// TODO Auto-generated destructor stub

}

void Hunter::wasShot(int damage)
{
    health = health - damage;
}

int Hunter::getLane()
{
    return lane;
}

std::string Hunter::getName()
{
    return "Hunter";
}

void Hunter::setLane(int givenLane)
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

void Hunter::moveCurrentKorat(float timePassed)
{
        if(hunter.getPosition().x > -100)
        {
            hunter.move(-speed * timePassed, 0);
            if(!((int)hunter.getPosition().x % 10))
                KoratEmpire::incrementRunFrame(&spriteFrame, &hunter);
        }
        else
        {
            survive = true;
        }
}

void Hunter::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(hunter);
}

sf::Sprite Hunter::getKorat()
{
    return hunter;
}

float Hunter::getPositionX()
{
    return hunter.getPosition().x;
}

bool Hunter::checkDeath()
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
            hunter.setTextureRect(spriteFrame);
			return false;
		}
    }
    else
    {
        postDeathClock.restart();
        return false;

    }
}

bool Hunter::checkSurvive()
{
    return survive;
}

int Hunter::getHealth()
{
    return health;
}

int Hunter::getSpeed()
{
    return speed;
}

double Hunter::getFireRate()
{
	return fireRate;
}

void Hunter::setFireRate(double givenFireRate)
{
	fireRate = givenFireRate;
}

bool Hunter::queryToFire()
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

