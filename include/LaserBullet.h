
#ifndef INCLUDE_LASERBULLET_H_
#define INCLUDE_LASERBULLET_H_

#include "Bullet.h"

class LaserBullet: public Bullet {

public:
	sf::RectangleShape laser;
	sf::Texture gruntPlasma;

	LaserBullet(int startLane);
	virtual ~LaserBullet();

	int getLane();

	void setLane(int givenLane);

	void moveCurrentBullet(float timePassed);

	void drawCurrentBullet(sf::RenderWindow& window);

	sf::RectangleShape getBullet();

	bool getOutOfBounds();

	float getPositionX();



private:

	int lane;
	int height;
	int speed = 500;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;

    int height1 = 268;
    int height2 = 227;
    int height3 = 185;
    int height4 = 144;
    int height5 = 102;

    bool outOfBounds = false;
};

#endif
