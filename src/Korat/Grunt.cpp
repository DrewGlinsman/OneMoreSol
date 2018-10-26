
#include "Grunt.h"
#include <iostream>

Grunt::Grunt(int startLane){
    lane = 0;

    if (!mtSpriteSheet.loadFromFile("assets/mtSpriteSheet.png"))
        std::cout << "Failed to Load mtSpriteSheet." << std::endl;

	grunt.setTexture(mtSpriteSheet);
	grunt.setTextureRect(sf::IntRect(0,448,64,64));
	grunt.setOrigin(sf::Vector2f(32.f, 32.f));
	setLane(startLane);
	grunt.setPosition(1500, lane);
	std::cout << "I'm a grunt" << std::endl;
}

Grunt::~Grunt() {
	// TODO Auto-generated destructor stub

}

void Grunt::wasShot(int damage)
{
	health - damage;
	if(health < 0)
    {
        //trigger grunt death
    }
}

int Grunt::getLane()
{
    return lane;
}

void Grunt::setLane(int givenLane)
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

void Grunt::moveCurrentKorat(float timePassed)
{
        if(grunt.getPosition().x > 500)
        {
            grunt.move(-speed * timePassed, 0);
        }
        else
        {
            health = 0;
        }
}

void Grunt::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(grunt);
}

sf::Sprite Grunt::getKorat()
{
    return grunt;
}

bool Grunt::checkDeath()
{
    if (health <= 0)
        return true;
    return false;
}
