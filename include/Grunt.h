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

	int getLane();
	void wasShot(int damage);

	void moveCurrentKorat(float timePassed);

	void drawCurrentKorat(sf::RenderWindow& window);

private:
	int lane;
	int speed = 100;
	int health = 100;
};

#endif /* INCLUDE_GRUNT_H_ */
