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

	Grunt(float startLane);
	virtual ~Grunt();

	void wasShot();

	void moveGrunt(float timePassed);

	void setLane(float lane);
	float getLane();

	void drawGrunt(sf::RenderWindow& window);

private:
	float lane;

};

#endif /* INCLUDE_GRUNT_H_ */
