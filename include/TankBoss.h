
#ifndef TANKBOSS_H
#define TANKBOSS_H

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

using namespace std;

class TankBoss {

    public:
        sf::RectangleShape tankBoss;

        TankBoss(TextureLoader* loadedTextures);

        float getBossPosition();

        float getPositionX();

        void setBossPosition(float positionPassed);

        void moveBoss(float timePassed);

        void drawBoss(sf::RenderWindow& window);

        bool checkDeath();

        bool checkSurvive();

        void wasShot(int damage);

        int getSpeed();

        bool queryToFire();

        int decideFiringLane();

        sf::RectangleShape getBoss();

    private:
        int speed = 10;
        int health = 500;
        bool survive = false;

        int lane1 = 335;
        int lane2 = 422;
        int lane3 = 508;
        int lane4 = 594;
        int lane5 = 680;

        int index = 0;

        std::vector<int> firingLane{lane1,lane2,lane1,lane2,lane4,lane5,lane4,lane5,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,

                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,

                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,

                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,

                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,
                                    lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3,lane3};

        float lastBulletFired;
        sf::Clock fireBulletClock;

        float postDeathTime;
        sf::Clock postDeathClock;
};

#endif
