#include "KoratBullet3.h"
#include <iostream>

using namespace std;

KoratBullet3::KoratBullet3(int givenLane, int givenHeight, TextureLoader* loadedTextures) {
    plasma.setTexture(loadedTextures->textureArray[0]);
    plasma.setTextureRect(sf::IntRect(480,32,32,32));
	//plasma.setSize(sf::Vector2f(16.f,16.f));
	plasma.setOrigin(sf::Vector2f(16.f,16.f));
	setLane(givenLane);
	plasma.setPosition(givenHeight, lane);
	speed = 500;
	damage = 5;

    firePlasmaPistol.setBuffer(plasmaPistolSound);
    firePlasmaPistol.setVolume(50);
    firePlasmaPistol.play();
}

KoratBullet3::~KoratBullet3() {
	// TODO Auto-generated destructor stub
}

int KoratBullet3::getDamage()
{
    return damage;
}

int KoratBullet3::getLane()
{
    return lane;
}

int KoratBullet3::getHeight()
{
    return height;
}

float KoratBullet3::getPositionX()
{
    return plasma.getPosition().x;
}

void KoratBullet3::setLane(int givenLane)
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

void KoratBullet3::moveCurrentBullet(float timePassed)
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

void KoratBullet3::drawCurrentBullet(sf::RenderWindow& window)
{
    window.draw(plasma);
}

bool KoratBullet3::getOutOfBounds()
{
    return outOfBounds;
}

sf::Sprite KoratBullet3::getBullet()
{
    return plasma;
}

int KoratBullet3::getType()
{
    return 8;
}


