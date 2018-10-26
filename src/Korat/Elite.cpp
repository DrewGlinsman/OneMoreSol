
#include "Elite.h"
#include <iostream>

Elite::Elite(int startLane){
    if(!gruntPlasma.loadFromFile("assets/plasmaGrunt.png"))
        std::cout << "Failed to load plasmaGrunt." << std::endl;
    lane = 0;
	elite.setSize(sf::Vector2f(64,64));
	elite.setTexture(&gruntPlasma);
	elite.setOrigin(elite.getSize().x / 2, elite.getSize().y /2);
	setLane(startLane);
	elite.setPosition(1500, lane);
	std::cout << "I'm a elite" << std::endl;
}

Elite::~Elite() {
	// TODO Auto-generated destructor stub

}

void Elite::wasShot(int damage)
{
	health - damage;
	if(health < 0)
    {
        //trigger elite death
    }
}

int Elite::getLane()
{
    return lane;
}

void Elite::setLane(int givenLane)
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

void Elite::moveCurrentKorat(float timePassed)
{
        if(elite.getPosition().x > -100)
        {
            elite.move(-speed * timePassed, 0);
        }
        else
        {
            health = 0;
        }
}

void Elite::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(elite);
}

sf::RectangleShape Elite::getKorat()
{
    return elite;
}

float Elite::getPositionX()
{
    return elite.getPosition().x;
}

bool Elite::checkDeath()
{
    if (health <= 0)
        return true;
    return false;
}
