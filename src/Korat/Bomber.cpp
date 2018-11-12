
#include "Bomber.h"
#include <iostream>

Bomber::Bomber(int startLane, TextureLoader* loadedTextures){

    lane = 0;

	bomber.setTexture(loadedTextures->textureArray[0]);
	spriteFrame.left = 0;//x
	spriteFrame.top = 704;//y
	spriteFrame.width = 64;
	spriteFrame.height = 64;
	bomber.setTextureRect(spriteFrame);
	bomber.setOrigin(sf::Vector2f(32.f,32.f));
	setLane(startLane);
	bomber.setPosition(1500, lane);
	bomber.setScale(sf::Vector2f(1.2f,1.2f));

}

Bomber::~Bomber() {
	// TODO Auto-generated destructor stub

}

void Bomber::wasShot(int damage)
{
    health = health - damage;
}

int Bomber::getLane()
{
    return lane;
}

std::string Bomber::getName()
{
    return "Bomber";
}

void Bomber::setLane(int givenLane)
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

void Bomber::moveCurrentKorat(float timePassed)
{
        if(bomber.getPosition().x > -100)
        {
            bomber.move(-speed * timePassed, 0);
            KoratEmpire::incrementRunFrame5(&spriteFrame, &bomber);
        }
        else
        {
            survive = true;
        }
}

void Bomber::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(bomber);
}

sf::Sprite Bomber::getKorat()
{
    return bomber;
}

float Bomber::getPositionX()
{
    return bomber.getPosition().x;
}

bool Bomber::checkDeath()
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

bool Bomber::checkSurvive()
{
    return survive;
}

int Bomber::getHealth()
{
    return health;
}

int Bomber::getSpeed()
{
    return speed;
}
