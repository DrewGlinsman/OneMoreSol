
#ifndef INCLUDE_ELITE_H_
#define INCLUDE_ELITE_H_

#include <SFML/Graphics.hpp>
#include "KoratEmpire.h"

class Elite: public KoratEmpire {
public:
	sf::RectangleShape elite;
	sf::Texture gruntPlasma;

	Elite(int startLane);
	virtual ~Elite();

	int getLane();

	void setLane(int givenLane);

	void wasShot(int damage);

	void moveCurrentKorat(float timePassed);

	void drawCurrentKorat(sf::RenderWindow& window);

private:

	int lane;
	int speed = 100;
	int health = 100;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;
};

#endif