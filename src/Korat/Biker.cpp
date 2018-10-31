
#include "Biker.h"
#include <iostream>

Biker::Biker(int startLane, TextureLoader* loadedTextures){
    lane = 0;

	biker.setTexture(loadedTextures->mtSpriteSheet);
	biker.setTextureRect(sf::IntRect(0,768,64,64));
	biker.setOrigin(sf::Vector2f(32.f,32.f));
	setLane(startLane);
	biker.setPosition(1500, lane);
	biker.setScale(sf::Vector2f(1.2f,1.2f));

}

Biker::~Biker() {
	// TODO Auto-generated destructor stub

}

void Biker::wasShot(int damage)
{
    health = health - damage;
}

int Biker::getLane()
{
    return lane;
}

std::string Biker::getName()
{
    return "Biker";
}

void Biker::setLane(int givenLane)
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

void Biker::moveCurrentKorat(float timePassed)
{
        if(biker.getPosition().x > -100)
        {
            biker.move(-speed * timePassed, 0);
        }
        else
        {
            survive = true;
        }
}

void Biker::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(biker);
}

sf::Sprite Biker::getKorat()
{
    return biker;
}

float Biker::getPositionX()
{
    return biker.getPosition().x;
}

bool Biker::checkDeath()
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
				koratDied.setBuffer(koratDeathSound);
				koratDied.setVolume(100);
				koratDied.play();
				koratDeathSoundPlayed = true;
			}
		}
    }
    else
    {
        postDeathClock.restart();
        return false;

    }
}

bool Biker::checkSurvive()
{
    return survive;
}
