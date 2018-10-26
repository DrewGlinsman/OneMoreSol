
#ifndef INCLUDE_BOMBER_H_
#define INCLUDE_BOMBER_H_

#include <SFML/Graphics.hpp>
#include "KoratEmpire.h"

class Bomber: public KoratEmpire {
public:
	sf::RectangleShape bomber;
	sf::Texture gruntPlasma;

	Bomber(int startLane);
	virtual ~Bomber();

	int getLane();

	void setLane(int givenLane);

	void wasShot(int damage);

	bool checkDeath();

	void moveCurrentKorat(float timePassed);

	void drawCurrentKorat(sf::RenderWindow& window);

	sf::RectangleShape getKorat();

	float getPositionX();

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
