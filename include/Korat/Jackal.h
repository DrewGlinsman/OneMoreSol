
#ifndef INCLUDE_JACKAL_H_
#define INCLUDE_JACKAL_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "KoratEmpire.h"
#include "TextureLoader.h"

class Jackal: public KoratEmpire {
public:
	sf::Sprite jackal;
	sf::IntRect spriteFrame;

	Jackal(int, TextureLoader*);
	virtual ~Jackal();

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

private:

	int lane;
	int speed = 200;
	int health = 100;
	bool survive = false;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;

    bool koratDeathSoundPlayed = false;
	bool koratLeftSoundPlayed = false;
    float postDeathTime;
	sf::Clock postDeathClock;
	sf::Clock postLeftClock;
	float postLeftTime;

	sf::SoundBuffer jackalHitSound;
    sf::Sound jackalWasHit;
    sf::SoundBuffer koratDeathSound;
    sf::Sound koratDied;
    sf::SoundBuffer koratLeftSound;
	sf::Sound koratLeft;
};

#endif
