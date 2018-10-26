
#ifndef INCLUDE_ARCBULLET_H_
#define INCLUDE_ARCBULLET_H_

#include "Bullet.h"

class ArcBullet: public Bullet {

public:
	sf::RectangleShape arc;
	sf::Texture gruntPlasma;

	ArcBullet(int startLane);
	virtual ~ArcBullet();

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
