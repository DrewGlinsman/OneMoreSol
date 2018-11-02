
#include "LaserMinigunBullet.h"
#include <iostream>

LaserMinigunBullet::LaserMinigunBullet(int startLane, TextureLoader* loadedTextures) {
    laser.setTexture(loadedTextures->mtSpriteSheet);
    laser.setTextureRect(sf::IntRect(256,96,32,32));
	laser.setOrigin(sf::Vector2f(16.f,16.f));
	setLane(startLane);
	laser.setPosition(height, lane);
	speed = 3000;
	damage = 20;

    if (!laserRifleSound.loadFromFile("assets/Laser_Rifle_Sound.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Laser Rifle Sound." << std::endl;

    fireLaserRifle.setBuffer(laserRifleSound);
    fireLaserRifle.setVolume(50);
    fireLaserRifle.play();
}

LaserMinigunBullet::~LaserMinigunBullet() {
	// TODO Auto-generated destructor stub
}

int LaserMinigunBullet::getDamage()
{
    return damage;
}

int LaserMinigunBullet::getLane()
{
    return lane;
}

int LaserMinigunBullet::getHeight()
{
    return height;
}

float LaserMinigunBullet::getPositionX()
{
    return laser.getPosition().x;
}

void LaserMinigunBullet::setLane(int givenLane)
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

void LaserMinigunBullet::moveCurrentBullet(float timePassed)
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

void LaserMinigunBullet::drawCurrentBullet(sf::RenderWindow& window)
{
    window.draw(laser);
}

bool LaserMinigunBullet::getOutOfBounds()
{
    return outOfBounds;
}

sf::Sprite LaserMinigunBullet::getBullet()
{
    return laser;
}

