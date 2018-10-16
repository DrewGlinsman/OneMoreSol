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

	Grunt();
	virtual ~Grunt();

	void wasShot();

	void drawGrunt(sf::RenderWindow& window);

};

#endif /* INCLUDE_GRUNT_H_ */
