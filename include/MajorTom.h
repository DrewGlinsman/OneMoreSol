
#ifndef MAJORTOM_H
#define MAJORTOM_H

#include <SFML/Graphics.hpp>
#include "Gun.h"
#include "PlasmaPistol.h"

using namespace std;

class MajorTom {

    private:
        float positionX;
        float positionY;
        float newPosition;
        float timePassed;
        int currentHealth;
        int newHealth;

    public:
        sf::Sprite majorTom;

        sf::Texture mtSpriteSheet;//this is a second load, loaded also on gameviewplayer. how to expand scope?

        sf::Sprite mtStandPPistol;

        Gun currentGun;

        MajorTom();

        void drawTom(sf::RenderWindow& window);

        float getTomPosition();

        void setTomPositionX(float positionPassed);

        void setTomPositionY(float positionPassed);

        bool initMove(float timePassed, string direction);

        bool keepMoving(float timePassed, string direction);

        void moveTomUp(float timePassed);

        void moveTomDown(float timePassed);

        void shoot(float timePassed);

        int getHealth();

        void setHealth(int newHealth);

        Gun getGun();

        void setGun(Gun newGun);

        bool checkDeath();

        void updateGame(sf::RenderWindow& gameWindow);

};

#endif
