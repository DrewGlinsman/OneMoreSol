/*
 * Grunt.cpp
 *
 *  Created on: Oct 14, 2018
 *      Author: jabowden
 */

#include <Grunt.h>
#include <iostream>

/**
 * @brief Grunts spawn with 100 health.
 */
Grunt::Grunt(int startLane){
    if(!gruntPlasma.loadFromFile("assets/plasmaGrunt.png"))
        std::cout << "Failed to load plasmaGrunt." << std::endl;

	grunt.setSize(sf::Vector2f(64,64));
	grunt.setTexture(&gruntPlasma);
	grunt.setOrigin(grunt.getSize().x / 2, grunt.getSize().y /2);
	setLane(startLane);
	grunt.setPosition(1500, lane);
	std::cout << "I'm a grunt" << std::endl;
}

Grunt::~Grunt() {
	// TODO Auto-generated destructor stub

}

/**
 * @brief Called when Grunt is damaged by bullet. Decreases health by 1.
 *
 */
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
    return this->lane;
}

void Grunt::moveCurrentKorat(float timePassed)
{
        if(grunt.getPosition().x > -5) //if grunt hasnt totally left the screen
    {
    	grunt.move(speed * timePassed,0);
    } else {
    	grunt.setPosition(1500,getLane());
    }
}

void Grunt::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(grunt);
    std::cout << "grunt was drawn" << std::endl;
}
