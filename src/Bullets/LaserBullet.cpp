
#include "LaserBullet.h"
#include <iostream>

LaserBullet::LaserBullet(int startLane) {
    //if(!gruntPlasma.loadFromFile("assets/plasmaGrunt.png"))
        //std::cout << "Failed to load plasmaGrunt." << std::endl;
    laser.setSize(sf::Vector2f(32,32));
	//laser.setTexture(&gruntPlasma);
	laser.setOrigin(laser.getSize().x / 2, laser.getSize().y /2);
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

sf::RectangleShape LaserBullet::getBullet()
{
    return laser;
}

