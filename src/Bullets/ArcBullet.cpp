
#include "ArcBullet.h"
#include <iostream>

ArcBullet::ArcBullet(int startLane) {
    //if(!gruntPlasma.loadFromFile("assets/plasmaGrunt.png"))
        //std::cout << "Failed to load plasmaGrunt." << std::endl;
    arc.setSize(sf::Vector2f(64,64));
	//arc.setTexture(&gruntPlasma);
	arc.setOrigin(arc.getSize().x / 2, arc.getSize().y /2);
	setLane(startLane);
	arc.setPosition(height, lane);
	speed = 100;
	damage = 40;
}

ArcBullet::~ArcBullet() {
	// TODO Auto-generated destructor stub
}

int ArcBullet::getLane()
{
    return lane;
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
        if(arc.getPosition().x < 1500)
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

sf::RectangleShape ArcBullet::getBullet()
{
    return arc;
}

