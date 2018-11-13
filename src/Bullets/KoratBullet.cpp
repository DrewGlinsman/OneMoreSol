/*
 * KoratBullet.cpp
 *
 *  Created on: Nov 10, 2018
 *      Author: Bowden
 */


#include "KoratBullet.h"
#include <iostream>

using namespace std;

KoratBullet::KoratBullet(int givenLane, int givenHeight, TextureLoader* loadedTextures) {
    plasma.setTexture(loadedTextures->textureArray[0]);
    plasma.setTextureRect(sf::IntRect(256,64,32,32));
	//plasma.setSize(sf::Vector2f(16.f,16.f));
	plasma.setOrigin(sf::Vector2f(16.f,16.f));
	setLane(givenLane);
	plasma.setPosition(givenHeight, lane);
	speed = 500;
	damage = 5;

	if (!plasmaPistolSound.loadFromFile("assets/Plasma_Pistol_Sound.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Plasma Pistol Sound." << std::endl;

    firePlasmaPistol.setBuffer(plasmaPistolSound);
    firePlasmaPistol.setVolume(50);
    firePlasmaPistol.play();
}

KoratBullet::~KoratBullet() {
	// TODO Auto-generated destructor stub
}

int KoratBullet::getDamage()
{
    return damage;
}

int KoratBullet::getLane()
{
    return lane;
}

int KoratBullet::getHeight()
{
    return height;
}

float KoratBullet::getPositionX()
{
    return plasma.getPosition().x;
}

void KoratBullet::setLane(int givenLane)
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

void KoratBullet::moveCurrentBullet(float timePassed)
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

void KoratBullet::drawCurrentBullet(sf::RenderWindow& window)
{
    window.draw(plasma);
}

bool KoratBullet::getOutOfBounds()
{
    return outOfBounds;
}

sf::Sprite KoratBullet::getBullet()
{
    return plasma;
}

