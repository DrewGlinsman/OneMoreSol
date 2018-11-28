
#ifndef BIKEBOSS_H
#define BIKEBOSS_H

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

using namespace std;

class BikeBoss {

    public:
        sf::Sprite bikeBoss;
        sf::IntRect spriteFrame;

        BikeBoss(TextureLoader* loadedTextures);

        float getBossPosition();

        float getPositionX();

        void setBossPosition(float positionPassed);

        bool moveBossUp(float timePassed);

        bool moveBossDown(float timePassed);

        void initBossUp();

        void initBossDown();

        void moveBoss(float timePassed);

        void incrementRunFrameBoss(sf::IntRect*, sf::Sprite*);

        void drawBoss(sf::RenderWindow& window);

        bool checkDeath();

        bool checkSurvive();

        void wasShot(int damage);

        int getSpeed();

        bool queryToFire();

        sf::Sprite getBoss();


    private:
        int speed = 40;
        int health = 500;
        bool survive = false;

        float lastBulletFired;
        sf::Clock fireBulletClock;

        float postDeathTime;
        sf::Clock postDeathClock;

        int lane2 = 422;
        int lane3 = 508;
        int lane4 = 594;

};

#endif
