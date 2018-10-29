
#ifndef INCLUDE_GRUNT_H_
#define INCLUDE_GRUNT_H_

#include <SFML/Graphics.hpp>
#include "KoratEmpire.h"
#include "TextureLoader.h"
#include <SFML/Audio.hpp>

class Grunt: public KoratEmpire {
public:
	sf::Sprite grunt;

	Grunt(int, TextureLoader*);
	virtual ~Grunt();

	int getLane();

	void setLane(int givenLane);

	void wasShot(int damage);

    bool checkDeath();

	void moveCurrentKorat(float timePassed);

	void drawCurrentKorat(sf::RenderWindow& window);

    sf::Sprite getKorat();

	float getPositionX();

	bool checkSurvive();

private:

	int lane;
	int speed = 100;
	int health = 100;
	bool survive = false;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;

    sf::SoundBuffer gruntHitSound;
    sf::Sound gruntWasHit;
};

#endif
