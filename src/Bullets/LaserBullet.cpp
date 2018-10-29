
#include "LaserBullet.h"
#include <iostream>

LaserBullet::LaserBullet(int startLane, TextureLoader* loadedTextures) {
    laser.setTexture(loadedTextures->mtSpriteSheet);
    laser.setTextureRect(sf::IntRect(256,96,32,32));
	laser.setOrigin(sf::Vector2f(16.f,16.f));
	setLane(startLane);
	laser.setPosition(height, lane);
	speed = 1000;
	damage = 20;
}

LaserBullet::~LaserBullet() {
	// TODO Auto-generated destructor stub
}

int LaserBullet::getDamage()
{
    return damage;
}

int LaserBullet::getLane()
{
    return lane;
}

float LaserBullet::getPositionX()
{
    return laser.getPosition().x;
}

void LaserBullet::setLane(int givenLane)
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

void LaserBullet::moveCurrentBullet(float timePassed)
{
        if(laser.getPosition().x < 1500)
        {
            laser.move(speed * timePassed, 0);
            outOfBounds = false;
        }
        else
        {
            outOfBounds = true;
        }
}

void LaserBullet::drawCurrentBullet(sf::RenderWindow& window)
{
    window.draw(laser);
}

bool LaserBullet::getOutOfBounds()
{
    return outOfBounds;
}

sf::Sprite LaserBullet::getBullet()
{
    return laser;
}

