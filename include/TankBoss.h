
#ifndef TANKBOSS_H
#define TANKBOSS_H

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

using namespace std;

class TankBoss {

    public:
        sf::Sprite tankBoss;
        sf::IntRect spriteFrame;

        TankBoss(TextureLoader* loadedTextures);

        float getBossPosition();

        void setBossPosition(float positionPassed);

        void moveBoss(float timePassed);

        void incrementRunFrameBoss(sf::IntRect*, sf::Sprite*);

        void drawBoss(sf::RenderWindow& window);

        bool checkDeath();

        bool checkSurvive();

        void wasShot(int damage);

        int getSpeed();

        sf::Sprite getBoss();

    private:
        int speed = 10;
        int health = 500;
        bool survive = false;

        float postDeathTime;
        sf::Clock postDeathClock;

        int lane3 = 508;
};

#endif
