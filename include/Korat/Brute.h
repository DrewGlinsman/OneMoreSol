
#ifndef INCLUDE_BRUTE_H_
#define INCLUDE_BRUTE_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "KoratEmpire.h"
#include "TextureLoader.h"
#include "rngs.h"

class Brute: public KoratEmpire {
public:
	sf::Sprite brute;
	sf::IntRect spriteFrame;

	Brute(int, TextureLoader*);
	virtual ~Brute();

	int getLane();

	std::string getName();

	void setLane(int givenLane);

	void wasShot(int damage);

	bool checkDeath();

	void moveCurrentKorat(float timePassed);

	void drawCurrentKorat(sf::RenderWindow& window);

	sf::Sprite getKorat();

	float getPositionX();

	bool checkSurvive();

	int getHealth();

	int getSpeed();

	double getFireRate();

	void setFireRate(double);

	bool queryToFire();

private:

	int lane;
	int speed = 75;
	int health = 150;
	bool survive = false;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;

    double fireRate = 2;
    float lastBulletFired;
    sf::Clock fireBulletClock;

    bool koratDeathSoundPlayed = false;
    float postDeathTime;
	sf::Clock postDeathClock;
	sf::Clock postLeftClock;
	float postLeftTime;

};

#endif
