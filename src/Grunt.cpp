/*
 * Grunt.cpp
 *
 *  Created on: Oct 14, 2018
 *      Author: jabowden
 */

#include <Grunt.h>

/**
 * @brief Grunts spawn with 100 health.
 */
Grunt::Grunt(float startLane) {
	grunt.setSize(sf::Vector2f(25,50));
	grunt.setOrigin(grunt.getSize().x / 2, grunt.getSize().y /2);
	grunt.setPosition(1500,startLane);
	setHealth(100);
	setSpeed(100);
}

Grunt::~Grunt() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief Called when Grunt is damaged by bullet. Decreases health by 1.
 *
 */
void Grunt::wasShot()
{
	setHealth(getHealth()-1);
}

void Grunt::moveGrunt(float timePassed)
{
    if(grunt.getPosition().x > 0)
    {
    	grunt.move(getSpeed() * timePassed,0);
    }
}

/**
 * @brief Called to draw Grunt
 */
void Grunt::drawGrunt (sf::RenderWindow& window)
{
    window.draw(grunt);
}
