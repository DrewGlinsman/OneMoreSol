
#include "Bomber.h"
#include <iostream>

Bomber::Bomber(int startLane){
    if(!gruntPlasma.loadFromFile("assets/plasmaGrunt.png"))
        std::cout << "Failed to load plasmaGrunt." << std::endl;
    lane = 0;
	bomber.setSize(sf::Vector2f(64,64));
	bomber.setTexture(&gruntPlasma);
	bomber.setOrigin(bomber.getSize().x / 2, bomber.getSize().y /2);
	setLane(startLane);
	bomber.setPosition(1500, lane);
	std::cout << "I'm a bomber" << std::endl;
}

Bomber::~Bomber() {
	// TODO Auto-generated destructor stub

}

void Bomber::wasShot(int damage)
{
	health - damage;
	if(health < 0)
    {
        //trigger bomber death
    }
}

int Bomber::getLane()
{
    return lane;
}

void Bomber::setLane(int givenLane)
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

void Bomber::moveCurrentKorat(float timePassed)
{
        if(bomber.getPosition().x > 500)
        {
            bomber.move(-speed * timePassed, 0);
        }
        else
        {
            health = 0;
        }
}

void Bomber::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(bomber);
}

bool Bomber::checkDeath()
{
    if (health <= 0)
        return true;
    return false;
}
