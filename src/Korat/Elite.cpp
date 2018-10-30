
#include "Elite.h"
#include <iostream>

Elite::Elite(int startLane, TextureLoader* loadedTextures){
    lane = 0;

	elite.setTexture(loadedTextures->mtSpriteSheet);
	elite.setTextureRect(sf::IntRect(0,512,64,64));
	elite.setOrigin(sf::Vector2f(32.f, 32.f));
	setLane(startLane);
	elite.setPosition(1500, lane);
	elite.setScale(sf::Vector2f(1.2f,1.2f));
	std::cout << "I'm a elite" << std::endl;
}

Elite::~Elite() {
	// TODO Auto-generated destructor stub

}

void Elite::wasShot(int damage)
{
    health = health - damage;
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
        if(elite.getPosition().x > -100)
        {
            elite.move(-speed * timePassed, 0);
        }
        else
        {
            survive = true;
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

float Elite::getPositionX()
{
    return elite.getPosition().x;
}

bool Elite::checkDeath()
{
    if (health <= 0)
        return true;
    return false;
}

bool Elite::checkSurvive()
{
    return survive;
}
