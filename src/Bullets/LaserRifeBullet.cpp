
#include "LaserRifleBullet.h"
#include <iostream>

LaserRifleBullet::LaserRifleBullet(int startLane, TextureLoader* loadedTextures) {
    laser.setTexture(loadedTextures->textureArray[0]);
    laser.setTextureRect(sf::IntRect(256,96,32,32));
	laser.setOrigin(sf::Vector2f(16.f,16.f));
	setLane(startLane);
	laser.setPosition(height + 20, lane);
	speed = 1000;
	damage = 30;
}

LaserRifleBullet::~LaserRifleBullet() {
	// TODO Auto-generated destructor stub
}

int LaserRifleBullet::getDamage()
{
    return damage;
}

int LaserRifleBullet::getLane()
{
    return lane;
}

int LaserRifleBullet::getHeight()
{
    return height;
}

float LaserRifleBullet::getPositionX()
{
    return laser.getPosition().x;
}

void LaserRifleBullet::setLane(int givenLane)
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

void LaserRifleBullet::moveCurrentBullet(float timePassed)
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

void LaserRifleBullet::drawCurrentBullet(sf::RenderWindow& window)
{
    window.draw(laser);
}

bool LaserRifleBullet::getOutOfBounds()
{
    return outOfBounds;
}

sf::Sprite LaserRifleBullet::getBullet()
{
    return laser;
}

int LaserRifleBullet::getType()
{
    return 3;
}

