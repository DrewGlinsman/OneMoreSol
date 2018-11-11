
#include "PlasmaPistolBullet.h"
#include <iostream>

PlasmaPistolBullet::PlasmaPistolBullet(int startLane, int givenHeight, TextureLoader* loadedTextures) {
    plasma.setTexture(loadedTextures->textureArray[0]);
    plasma.setTextureRect(sf::IntRect(256,64,32,32));
	plasma.setOrigin(sf::Vector2f(16.f,16.f));
	setLane(startLane, givenHeight);
	plasma.setPosition(height, lane);
	speed = 500;
	damage = 35;

	if (!plasmaPistolSound.loadFromFile("assets/Plasma_Pistol_Sound.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Plasma Pistol Sound." << std::endl;

    firePlasmaPistol.setBuffer(plasmaPistolSound);
    firePlasmaPistol.setVolume(50);
    firePlasmaPistol.play();
}

PlasmaPistolBullet::~PlasmaPistolBullet() {
	// TODO Auto-generated destructor stub
}

int PlasmaPistolBullet::getDamage()
{
    return damage;
}

int PlasmaPistolBullet::getLane()
{
    return lane;
}

int PlasmaPistolBullet::getHeight()
{
    return height;
}

float PlasmaPistolBullet::getPositionX()
{
    return plasma.getPosition().x;
}

void PlasmaPistolBullet::setLane(int givenLane, int givenHeight)
{
     switch(givenLane)
	{
		case 1:
			lane = lane1;
			if (givenHeight == -1)
			{
				height = height1;
			} else {
				height = givenHeight;
			}
			break;
		case 2:
			lane = lane2;
			height = height2;
			if (givenHeight == -1)
			{
				height = height2;
			} else {
				height = givenHeight;
			}
			break;
		case 3:
			lane = lane3;
			height = height3;
			if (givenHeight == -1)
			{
				height = height3;
			} else {
				height = givenHeight;
			}
			break;
		case 4:
			lane = lane4;
			height = height4;
			if (givenHeight == -1)
			{
				height = height4;
			} else {
				height = givenHeight;
			}
			break;
		case 5:
			lane = lane5;
			height = height5;
			if (givenHeight == -1)
			{
				height = height5;
			} else {
				height = givenHeight;
			}
			break;
		default:
			lane = lane1;
			height = height1;
			break;
	}
}

void PlasmaPistolBullet::moveCurrentBullet(float timePassed)
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

void PlasmaPistolBullet::drawCurrentBullet(sf::RenderWindow& window)
{
    window.draw(plasma);
}

bool PlasmaPistolBullet::getOutOfBounds()
{
    return outOfBounds;
}

sf::Sprite PlasmaPistolBullet::getBullet()
{
    return plasma;
}

