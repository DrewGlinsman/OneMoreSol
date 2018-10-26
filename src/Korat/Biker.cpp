
#include "Biker.h"
#include <iostream>

Biker::Biker(int startLane, TextureLoader* loadedTextures){
    lane = 0;

	biker.setTexture(loadedTextures->mtSpriteSheet);
	biker.setTextureRect(sf::IntRect(0,768,64,64));
	biker.setOrigin(sf::Vector2f(32.f,32.f));
	setLane(startLane);
	biker.setPosition(1500, lane);
	std::cout << "I'm a biker" << std::endl;
}

Biker::~Biker() {
	// TODO Auto-generated destructor stub

}

void Biker::wasShot(int damage)
{
	health - damage;
	if(health < 0)
    {
        //trigger biker death
    }
}

int Biker::getLane()
{
    return lane;
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
        if(biker.getPosition().x > 500)
        {
            biker.move(-speed * timePassed, 0);
        }
        else
        {
            health = 0;
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

bool Biker::checkDeath()
{
    if (health <= 0)
        return true;
    return false;
}
