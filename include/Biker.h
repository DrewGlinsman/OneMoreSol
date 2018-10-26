
#ifndef INCLUDE_BIKER_H_
#define INCLUDE_BIKER_H_

#include <SFML/Graphics.hpp>
#include "KoratEmpire.h"

class Biker: public KoratEmpire {
public:
	sf::RectangleShape biker;
	sf::Texture gruntPlasma;

	Biker(int startLane);
	virtual ~Biker();

	int getLane();

	void setLane(int givenLane);

	void wasShot(int damage);

    bool checkDeath();

	void moveCurrentKorat(float timePassed);

	void drawCurrentKorat(sf::RenderWindow& window);

	sf::RectangleShape getKorat();

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
