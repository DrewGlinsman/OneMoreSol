
#include "PlasmaBullet.h"
#include <iostream>

PlasmaBullet::PlasmaBullet(int startLane) {
    //if(!gruntPlasma.loadFromFile("assets/plasmaGrunt.png"))
        //std::cout << "Failed to load plasmaGrunt." << std::endl;
    plasma.setSize(sf::Vector2f(16,16));
	//plasma.setTexture(&gruntPlasma);
	plasma.setOrigin(plasma.getSize().x / 2, plasma.getSize().y /2);
	setLane(startLane);
	plasma.setPosition(height, lane);
}

PlasmaBullet::~PlasmaBullet() {
	// TODO Auto-generated destructor stub
}

int PlasmaBullet::getDamage()
{
    return damage;
}

int PlasmaBullet::getLane()
{
    return lane;
}

float PlasmaBullet::getPositionX()
{
    return plasma.getPosition().x;
}

void PlasmaBullet::setLane(int givenLane)
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

void PlasmaBullet::moveCurrentBullet(float timePassed)
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

void PlasmaBullet::drawCurrentBullet(sf::RenderWindow& window)
{
    window.draw(plasma);
}

bool PlasmaBullet::getOutOfBounds()
{
    return outOfBounds;
}

sf::RectangleShape PlasmaBullet::getBullet()
{
    return plasma;
}

