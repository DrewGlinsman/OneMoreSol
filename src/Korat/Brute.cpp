
#include "Brute.h"
#include <iostream>

Brute::Brute(int startLane, TextureLoader* loadedTextures){
    lane = 0;

	brute.setTexture(loadedTextures->mtSpriteSheet);
	brute.setTextureRect(sf::IntRect(0,448,64,64));
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

bool Brute::checkSurvive()
{
    return survive;
}
