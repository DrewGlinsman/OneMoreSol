
#include "GaussBullet.h"
#include <iostream>

GaussBullet::GaussBullet(int startLane) {
    //if(!gruntPlasma.loadFromFile("assets/plasmaGrunt.png"))
        //std::cout << "Failed to load plasmaGrunt." << std::endl;
    gauss.setSize(sf::Vector2f(16,16));
	//gauss.setTexture(&gruntPlasma);
	gauss.setOrigin(gauss.getSize().x / 2, gauss.getSize().y /2);
	setLane(startLane);
	gauss.setPosition(height, lane);
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

sf::RectangleShape GaussBullet::getBullet()
{
    return gauss;
}

