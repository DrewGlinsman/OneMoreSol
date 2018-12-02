
#include "BFGBullet.h"
#include <iostream>

BFGBullet::BFGBullet(int startLane, TextureLoader* loadedTextures) {
    blast.setTexture(loadedTextures->textureArray[0]);
    blast.setTextureRect(sf::IntRect(256,256,192,192));
	blast.setOrigin(sf::Vector2f(96.f,96.f));
	setLane(startLane);
	blast.setPosition(height, lane);
	speed = 100;
	damage = 40;
}

BFGBullet::~BFGBullet() {
	// TODO Auto-generated destructor stub
}

int BFGBullet::getDamage()
{
    return damage;
}

int BFGBullet::getLane()
{
    return lane;
}

int BFGBullet::getHeight()
{
    return height;
}

float BFGBullet::getPositionX()
{
    return blast.getPosition().x;
}

void BFGBullet::setLane(int givenLane)
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

void BFGBullet::moveCurrentBullet(float timePassed)
{
        if(blast.getPosition().x < 250)
        {
            blast.move(speed * timePassed, 0);
            outOfBounds = false;
        }
        else
        {
            outOfBounds = true;
        }
}

void BFGBullet::drawCurrentBullet(sf::RenderWindow& window)
{
    window.draw(blast);
}

bool BFGBullet::getOutOfBounds()
{
    return outOfBounds;
}

sf::Sprite BFGBullet::getBullet()
{
    return blast;
}

std::string BFGBullet::getType()
{
    return "BFG";
}
