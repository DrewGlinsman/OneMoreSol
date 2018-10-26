
#include "Brute.h"
#include <iostream>

Brute::Brute(int startLane){
    if(!gruntPlasma.loadFromFile("assets/plasmaGrunt.png"))
        std::cout << "Failed to load plasmaGrunt." << std::endl;
    lane = 0;
	brute.setSize(sf::Vector2f(64,64));
	brute.setTexture(&gruntPlasma);
	brute.setOrigin(brute.getSize().x / 2, brute.getSize().y /2);
	setLane(startLane);
	brute.setPosition(1500, lane);
	std::cout << "I'm a brute" << std::endl;
}

Brute::~Brute() {
	// TODO Auto-generated destructor stub

}

void Brute::wasShot(int damage)
{
    health = health - damage;
}

int Brute::getLane()
{
    return lane;
}

void Brute::setLane(int givenLane)
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

void Brute::moveCurrentKorat(float timePassed)
{
        if(brute.getPosition().x > -100)
        {
            brute.move(-speed * timePassed, 0);
        }
        else
        {
            health = 0;
        }
}

void Brute::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(brute);
}

sf::RectangleShape Brute::getKorat()
{
    return brute;
}

float Brute::getPositionX()
{
    return brute.getPosition().x;
}

bool Brute::checkDeath()
{
    if (health <= 0)
        return true;
    return false;
}
