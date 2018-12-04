
#ifndef INCLUDE_BOMBER_H_
#define INCLUDE_BOMBER_H_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "KoratEmpire.h"
#include "TextureLoader.h"

class Bomber: public KoratEmpire {
public:
	sf::Sprite bomber;
	sf::IntRect spriteFrame;

	Bomber(int, TextureLoader*);
	virtual ~Bomber();

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

	void explode(std::vector<std::vector<std::shared_ptr<KoratEmpire>>> &currentKorat);

private:

	int lane;
	int speed = 100;
	int health = 175;
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
