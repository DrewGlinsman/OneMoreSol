#include "KoratBullet4.h"
#include <iostream>

using namespace std;

KoratBullet4::KoratBullet4(int givenLane, int givenHeight, TextureLoader* loadedTextures) {
    plasma.setTexture(loadedTextures->textureArray[0]);
    plasma.setTextureRect(sf::IntRect(847,847,32,32));
	plasma.setOrigin(sf::Vector2f(16.f,16.f));
	setLane(givenLane);
	plasma.setPosition(givenHeight, lane);
	speed = 500;
	damage = 10;
}

KoratBullet4::~KoratBullet4() {
	// TODO Auto-generated destructor stub
}

int KoratBullet4::getDamage()
{
    return damage;
}

int KoratBullet4::getLane()
{
    return lane;
}

int KoratBullet4::getHeight()
{
    return height;
}

float KoratBullet4::getPositionX()
{
    return plasma.getPosition().x;
}

void KoratBullet4::setLane(int givenLane)
{
	switch(givenLane)
	{
		case 335:
			lane = lane1;
			break;
		case 422:
			lane = lane2;
			break;
		case 508:
			lane = lane3;
			break;
		case 594:
			lane = lane4;
			break;
		case 680:
			lane = lane5;
			break;
		default:
			lane = lane1;
			break;
	}
}

void KoratBullet4::moveCurrentBullet(float timePassed)
{
        if(plasma.getPosition().x > -100)
        {
            plasma.move(-speed * timePassed, 0);
            outOfBounds = false;
        }
        else
        {
            outOfBounds = true;
        }
}

void KoratBullet4::drawCurrentBullet(sf::RenderWindow& window)
{
    window.draw(plasma);
}

bool KoratBullet4::getOutOfBounds()
{
    return outOfBounds;
}

sf::Sprite KoratBullet4::getBullet()
{
    return plasma;
}

int KoratBullet4::getType()
{
    return 8;
}


