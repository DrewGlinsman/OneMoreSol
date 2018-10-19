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
Grunt::Grunt(int startLane) {
	grunt.setSize(sf::Vector2f(25,50));
	grunt.setOrigin(grunt.getSize().x / 2, grunt.getSize().y /2);
	setLane(startLane);
	grunt.setPosition(1500,getLane());
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
    if(grunt.getPosition().x > -1) //if grunt hasnt totally left the screen
    {
    	grunt.move(getSpeed() * timePassed,0);
    } else {
    	grunt.setPosition(1500,getLane());
    }
}

/**
 * @brief Called to draw Grunt
 */
void Grunt::drawGrunt (sf::RenderWindow& window)
{
    window.draw(grunt);
}
