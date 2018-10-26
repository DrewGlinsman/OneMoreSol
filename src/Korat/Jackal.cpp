
#include "Jackal.h"
#include <iostream>

Jackal::Jackal(int startLane){
    if(!gruntPlasma.loadFromFile("assets/plasmaGrunt.png"))
        std::cout << "Failed to load plasmaGrunt." << std::endl;
    lane = 0;
	jackal.setSize(sf::Vector2f(64,64));
	jackal.setTexture(&gruntPlasma);
	jackal.setOrigin(jackal.getSize().x / 2, jackal.getSize().y /2);
	setLane(startLane);
	jackal.setPosition(1500, lane);
	std::cout << "I'm a jackal" << std::endl;
}

Jackal::~Jackal() {
	// TODO Auto-generated destructor stub

}

void Jackal::wasShot(int damage)
{
    health = health - damage;
}

int Jackal::getLane()
{
    return lane;
}

void Jackal::setLane(int givenLane)
{
     switch(givenLane)
	{
		case 1:
			lane = lane1;
			break;
		case 2:
			lane = lane2;
			break;
		case 3:
			lane = lane3;
			break;
		case 4:
			lane = lane4;
			break;
		case 5:
			lane = lane5;
			break;
		default:
			lane = lane1;
			break;
	}
}

void Jackal::moveCurrentKorat(float timePassed)
{
        if(jackal.getPosition().x > -100)
        {
            jackal.move(-speed * timePassed, 0);
        }
        else
        {
            health = 0;
        }
}

void Jackal::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(jackal);
}

sf::RectangleShape Jackal::getKorat()
{
    return jackal;
}

float Jackal::getPositionX()
{
    return jackal.getPosition().x;
}

bool Jackal::checkDeath()
{
    if (health <= 0)
        return true;
    return false;
}
