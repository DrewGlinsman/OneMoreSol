
#include "Jackal.h"
#include <iostream>

Jackal::Jackal(int startLane, TextureLoader* loadedTextures){
    lane = 0;

	jackal.setTexture(loadedTextures->mtSpriteSheet);
	jackal.setTextureRect(sf::IntRect(0,576,64,64));
	jackal.setOrigin(sf::Vector2f(32.f,32.f));
	setLane(startLane);
	jackal.setPosition(1500, lane);
	std::cout << "I'm a jackal" << std::endl;
}

Jackal::~Jackal() {
	// TODO Auto-generated destructor stub

}

void Jackal::wasShot(int damage)
{
	health - damage;
	if(health < 0)
    {
        //trigger jackal death
    }
}

int Jackal::getLane()
{
    return lane;
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
        if(jackal.getPosition().x > 500)
        {
            jackal.move(-speed * timePassed, 0);
        }
        else
        {
            health = 0;
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

bool Jackal::checkDeath()
{
    if (health <= 0)
        return true;
    return false;
}
