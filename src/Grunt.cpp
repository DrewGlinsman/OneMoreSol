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
Grunt::Grunt() {
	// TODO Auto-generated constructor stub
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

/**
 * @brief Called to draw Grunt
 */
void Grunt::drawGrunt (sf::RenderWindow& window)
{
    window.draw(grunt);
}
