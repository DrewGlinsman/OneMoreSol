
#ifndef INCLUDE_KORATEMPIRE_H_
#define INCLUDE_KORATEMPIRE_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextureLoader.h"

class KoratEmpire {
public:
    sf::Sprite korat;
    sf::IntRect spriteFrame;

    KoratEmpire();
    KoratEmpire(int, TextureLoader*);
	virtual ~KoratEmpire();

	virtual bool checkDeath();

	//were non virtual
	virtual void setLane(int givenLane);

	virtual int getLane();
    //end

	virtual std::string getName();

	//was non virtual
	virtual void incrementRunFrame(sf::IntRect*, sf::Sprite*);
	virtual void incrementRunFrame5(sf::IntRect*, sf::Sprite*);

	virtual void moveCurrentKorat(float timepassed);

	//were non virtual
	virtual void drawCurrentKorat(sf::RenderWindow& window);

	virtual float getPositionX();
    //end

	virtual void wasShot(int damage);

	sf::Sprite getKorat();

	virtual bool checkSurvive();

	virtual int getHealth();

	virtual int getSpeed();


    int lane;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;


private:

	int speed = 100;
	int health = 100;
	bool survive = false;

    int koratType;

};

#endif
