/*
 * Grunt.h
 *
 *  Created on: Oct 14, 2018
 *      Author: jabowden
 */

#ifndef INCLUDE_GRUNT_H_
#define INCLUDE_GRUNT_H_

#include <SFML/Graphics.hpp>
#include "KoratEmpire.h"

class Grunt: public KoratEmpire {
public:
	sf::RectangleShape grunt;
	sf::Texture gruntPlasma;

	Grunt(int startLane);
	virtual ~Grunt();

	void wasShot();

	void moveGrunt(float timePassed);

	void drawGrunt(sf::RenderWindow& window);

private:
    int maxEnemySpeedRand = 150;
    int minEnemySpeedRand = 75;
	int lane;
};

#endif /* INCLUDE_GRUNT_H_ */
