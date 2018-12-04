#ifndef INCLUDE_KoratBullet3_H_
#define INCLUDE_KoratBullet3_H_

#include "Bullet.h"
#include "TextureLoader.h"
#include <SFML/Audio.hpp>

class KoratBullet3: public Bullet {
public:
	sf::Sprite plasma;

	KoratBullet3(int, int, TextureLoader*);
	virtual ~KoratBullet3();

	int getDamage();

	int getLane();

	void setLane(int givenLane);

	void moveCurrentBullet(float timePassed);

	void drawCurrentBullet(sf::RenderWindow& window);

	sf::Sprite getBullet();

	bool getOutOfBounds();

	float getPositionX();

	int getHeight();

	int getType();

private:

	int lane;
	int height;
	int speed;
	int damage;
	int givenHeight;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;

    bool outOfBounds = false;

    sf::SoundBuffer plasmaPistolSound;
    sf::Sound firePlasmaPistol;
};

#endif

