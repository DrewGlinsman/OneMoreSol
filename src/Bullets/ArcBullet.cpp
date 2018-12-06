
#include "ArcBullet.h"
#include <iostream>

ArcBullet::ArcBullet(int startLane, TextureLoader* loadedTextures) {
    arc.setTexture(loadedTextures->textureArray[0]);
    arc.setTextureRect(sf::IntRect(256,256,192,192));
	arc.setOrigin(sf::Vector2f(96.f,96.f));
	setLane(startLane);
	arc.setPosition(height + 75, lane);
	speed = 1000;
	damage = 20;
}

ArcBullet::~ArcBullet() {
	// TODO Auto-generated destructor stub
}

int ArcBullet::getDamage()
{
    return damage;
}

int ArcBullet::getLane()
{
    return lane;
}

int ArcBullet::getHeight()
{
    return height;
}

float ArcBullet::getPositionX()
{
    return arc.getPosition().x;
}

void ArcBullet::setLane(int givenLane)
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

void ArcBullet::moveCurrentBullet(float timePassed)
{
        if(arc.getPosition().x < 650)
        {
            arc.move(speed * timePassed, 0);
            outOfBounds = false;
        }
        else
        {
            outOfBounds = true;
        }
}

void ArcBullet::drawCurrentBullet(sf::RenderWindow& window)
{
    window.draw(arc);
}

bool ArcBullet::getOutOfBounds()
{
    return outOfBounds;
}

sf::Sprite ArcBullet::getBullet()
{
    return arc;
}

int ArcBullet::getType()
{
    return 5;
}
