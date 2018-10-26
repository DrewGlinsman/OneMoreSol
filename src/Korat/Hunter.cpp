
#include "Hunter.h"
#include <iostream>

Hunter::Hunter(int startLane){
    if(!gruntPlasma.loadFromFile("assets/plasmaGrunt.png"))
        std::cout << "Failed to load plasmaGrunt." << std::endl;
    lane = 0;
	hunter.setSize(sf::Vector2f(64,64));
	hunter.setTexture(&gruntPlasma);
	hunter.setOrigin(hunter.getSize().x / 2, hunter.getSize().y /2);
	setLane(startLane);
	hunter.setPosition(1500, lane);
	std::cout << "I'm a hunter" << std::endl;
}

Hunter::~Hunter() {
	// TODO Auto-generated destructor stub

}

void Hunter::wasShot(int damage)
{
    health = health - damage;
}

int Hunter::getLane()
{
    return lane;
}

void Hunter::setLane(int givenLane)
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

void Hunter::moveCurrentKorat(float timePassed)
{
        if(hunter.getPosition().x > -100)
        {
            hunter.move(-speed * timePassed, 0);
        }
        else
        {
            health = 0;
        }
}

void Hunter::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(hunter);
}

sf::RectangleShape Hunter::getKorat()
{
    return hunter;
}

float Hunter::getPositionX()
{
    return hunter.getPosition().x;
}

bool Hunter::checkDeath()
{
    if (health <= 0)
        return true;
    return false;
}
