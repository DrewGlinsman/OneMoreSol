
#include "PlasmaBullet.h"
#include <iostream>

PlasmaBullet::PlasmaBullet(int startLane, TextureLoader* loadedTextures) {
    plasma.setTexture(loadedTextures->mtSpriteSheet);
    plasma.setTextureRect(sf::IntRect(256,64,32,32));
	plasma.setOrigin(sf::Vector2f(32.f,32.f));
	setLane(startLane);
	plasma.setPosition(height, lane);
	speed = 500;
	damage = 35;
}

PlasmaBullet::~PlasmaBullet() {
	// TODO Auto-generated destructor stub
}

int PlasmaBullet::getDamage()
{
    return damage;
}

int PlasmaBullet::getLane()
{
    return lane;
}

float PlasmaBullet::getPositionX()
{
    return plasma.getPosition().x;
}

void PlasmaBullet::setLane(int givenLane)
{
     switch(givenLane)
	{
		case 1:
			lane = lane1;
			height = height1;
			break;
		case 2:
			lane = lane2;
			height = height2;
			break;
		case 3:
			lane = lane3;
			height = height3;
			break;
		case 4:
			lane = lane4;
			height = height4;
			break;
		case 5:
			lane = lane5;
			height = height5;
			break;
		default:
			lane = lane1;
			height = height1;
			break;
	}
}

void PlasmaBullet::moveCurrentBullet(float timePassed)
{
        if(plasma.getPosition().x < 1500)
        {
            plasma.move(speed * timePassed, 0);
            outOfBounds = false;
        }
        else
        {
            outOfBounds = true;
        }
}

void PlasmaBullet::drawCurrentBullet(sf::RenderWindow& window)
{
    window.draw(plasma);
}

bool PlasmaBullet::getOutOfBounds()
{
    return outOfBounds;
}

sf::Sprite PlasmaBullet::getBullet()
{
    return plasma;
}

