
#ifndef INCLUDE_KORATEMPIRE_H_
#define INCLUDE_KORATEMPIRE_H_

#include <SFML/Graphics.hpp>
#include <iostream>

class KoratEmpire {
public:
	KoratEmpire();
	virtual ~KoratEmpire();

	virtual bool checkDeath();

	virtual void setLane(int givenLane);

	virtual int getLane();

	virtual std::string getName();

	virtual void moveCurrentKorat(float timepassed);

	virtual void drawCurrentKorat(sf::RenderWindow& window);

	virtual float getPositionX();

	virtual void wasShot(int damage);

	sf::RectangleShape getKorat();

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
	unsigned int health;

    int koratType;

};

#endif
