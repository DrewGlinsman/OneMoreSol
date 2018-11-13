
#include "Jackal.h"
#include <iostream>

Jackal::Jackal(int startLane, TextureLoader* loadedTextures){
    lane = 0;

	jackal.setTexture(loadedTextures->textureArray[0]);
	spriteFrame.left = 0;//x
	spriteFrame.top = 576;//y
	spriteFrame.width = 64;
	spriteFrame.height = 64;
	jackal.setTextureRect(spriteFrame);
	jackal.setOrigin(sf::Vector2f(32.f,32.f));
	setLane(startLane);
	jackal.setPosition(1500, lane);
	jackal.setScale(sf::Vector2f(1.2f,1.2f));

    if (!jackalHitSound.loadFromFile("assets/Grunt_Hit.ogg")) // Loads and initializes all sounds based on impact
	    std::cout << "Could not load Grunt Hit Sound." << std::endl;
    if (!koratDeathSound.loadFromFile("assets/Korat_Death.ogg")) // Loads and initializes all sounds based on impact
		std::cout << "Could not load Korat Death Sound." << std::endl;
    if (!koratLeftSound.loadFromFile("assets/Korat_Left.ogg")) // Loads and initializes all sounds based on impact
		std::cout << "Could not load Korat Left Sound." << std::endl;
}

Jackal::~Jackal() {
	// TODO Auto-generated destructor stub

}

void Jackal::wasShot(int damage)
{
    health = health - damage;
    jackalWasHit.setBuffer(jackalHitSound);
	jackalWasHit.setVolume(75);
	jackalWasHit.play();

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
				koratDied.setBuffer(koratDeathSound);
				koratDied.setVolume(100);
				koratDied.play();
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
