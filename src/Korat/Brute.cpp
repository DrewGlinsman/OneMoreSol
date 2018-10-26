
#include "Brute.h"
#include <iostream>

Brute::Brute(int startLane, TextureLoader* loadedTextures){
    lane = 0;

	brute.setTexture(loadedTextures->mtSpriteSheet);
	brute.setTextureRect(sf::IntRect(0,448,64,64));
	brute.setOrigin(sf::Vector2f(32.f,32.f));
	setLane(startLane);
	brute.setPosition(1500, lane);
	std::cout << "I'm a brute" << std::endl;
}

Brute::~Brute() {
	// TODO Auto-generated destructor stub

}

void Brute::wasShot(int damage)
{
	health - damage;
	if(health < 0)
    {
        //trigger brute death
    }
}

int Brute::getLane()
{
    return lane;
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
        if(brute.getPosition().x > 500)
        {
            brute.move(-speed * timePassed, 0);
        }
        else
        {
            health = 0;
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

bool Brute::checkDeath()
{
    if (health <= 0)
        return true;
    return false;
}
