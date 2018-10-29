
#include "Bomber.h"
#include <iostream>

Bomber::Bomber(int startLane, TextureLoader* loadedTextures){

    lane = 0;

	bomber.setTexture(loadedTextures->mtSpriteSheet);
	bomber.setTextureRect(sf::IntRect(0,704,64,64));
	bomber.setOrigin(sf::Vector2f(32.f,32.f));
	setLane(startLane);
	bomber.setPosition(1500, lane);
	std::cout << "I'm a bomber" << std::endl;
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
        return true;
    return false;
}

bool Bomber::checkSurvive()
{
    return survive;
}
