
#ifndef INCLUDE_GRUNT_H_
#define INCLUDE_GRUNT_H_

#include <SFML/Graphics.hpp>
#include "KoratEmpire.h"
#include "TextureLoader.h"

class Grunt: public KoratEmpire {
public:
	sf::Sprite grunt;
	sf::IntRect spriteFrame;

	Grunt(int, TextureLoader*);
	virtual ~Grunt();

	int getLane();

	std::string getName();

	void setLane(int givenLane);

	void wasShot(int damage);

    bool checkDeath();

	void moveCurrentKorat(float timePassed);

	void drawCurrentKorat(sf::RenderWindow& window);

    sf::Sprite getKorat();

	float getPositionX();

	//should be in koratempire as same for all classes
	int getHealth();
	int getSpeed();
	bool checkSurvive();

private:

	int lane;
	int speed = 250;
    int health = 100;
	bool survive = false;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;

    bool koratDeathSoundPlayed = false;
	float postDeathTime;
	sf::Clock postDeathClock;
	sf::Clock postLeftClock;
	float postLeftTime;
};

#endif
