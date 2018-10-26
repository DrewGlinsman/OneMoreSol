
#ifndef INCLUDE_GAUSBULLET_H_
#define INCLUDE_GAUSSBULLET_H_

#include "Bullet.h"

class GaussBullet: public Bullet {

public:
	sf::RectangleShape gauss;
	sf::Texture gruntPlasma;

	GaussBullet(int startLane);
	virtual ~GaussBullet();

	int getLane();

	void setLane(int givenLane);

	void moveCurrentBullet(float timePassed);

	void drawCurrentBullet(sf::RenderWindow& window);

	sf::RectangleShape getBullet();

	bool getOutOfBounds();

	float getPositionX();



private:

	int lane;
	int speed = 500;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;

    bool outOfBounds = false;
};

#endif

