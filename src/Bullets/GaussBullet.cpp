
#include "GaussBullet.h"
#include <iostream>

GaussBullet::GaussBullet(int startLane, TextureLoader* loadedTextures) {
    gauss.setTexture(loadedTextures->mtSpriteSheet);
    gauss.setTextureRect(sf::IntRect(320,128,1000,32));
	gauss.setOrigin(sf::Vector2f(16.f,16.f));
	setLane(startLane);
	gauss.setPosition(height, lane);
	speed = 2000;
	damage = 50;
}

GaussBullet::~GaussBullet() {
	// TODO Auto-generated destructor stub
}

int GaussBullet::getLane()
{
    return lane;
}

float GaussBullet::getPositionX()
{
    return gauss.getPosition().x;
}

void GaussBullet::setLane(int givenLane)
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

void GaussBullet::moveCurrentBullet(float timePassed)
{
        if(gauss.getPosition().x < 1500)
        {
            gauss.move(speed * timePassed, 0);
            outOfBounds = false;
        }
        else
        {
            outOfBounds = true;
        }
}

void GaussBullet::drawCurrentBullet(sf::RenderWindow& window)
{
    window.draw(gauss);
}

bool GaussBullet::getOutOfBounds()
{
    return outOfBounds;
}

sf::Sprite GaussBullet::getBullet()
{
    return gauss;
}

