
#include "Elite.h"
#include <iostream>

Elite::Elite(int startLane, TextureLoader* loadedTextures){
    lane = 0;

	elite.setTexture(loadedTextures->mtSpriteSheet);
	elite.setTextureRect(sf::IntRect(0,512,64,64));
	elite.setOrigin(sf::Vector2f(32.f, 32.f));
	setLane(startLane);
	elite.setPosition(1500, lane);
	std::cout << "I'm a elite" << std::endl;
}

Elite::~Elite() {
	// TODO Auto-generated destructor stub

}

void Elite::wasShot(int damage)
{
	health - damage;
	if(health < 0)
    {
        //trigger elite death
    }
}

int Elite::getLane()
{
    return lane;
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
        if(elite.getPosition().x > 500)
        {
            elite.move(-speed * timePassed, 0);
        }
        else
        {
            health = 0;
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

bool Elite::checkDeath()
{
    if (health <= 0)
        return true;
    return false;
}
