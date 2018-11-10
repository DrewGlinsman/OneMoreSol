
#ifndef BIKEBOSS_H
#define BIKEBOSS_H

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

using namespace std;

class BikeBoss {

    public:
        sf::RectangleShape bikeBoss;

        sf::Texture mtSpriteSheet;//this is a second load, loaded also on gameviewplayer. how to expand scope?

        BikeBoss();

        float getBossPosition();

        void setBossPosition(float positionPassed);

        bool moveBossUp(float timePassed);

        bool moveBossDown(float timePassed);

        void initBossUp();

        void initBossDown();

        void moveBoss(float timePassed);

        void drawBoss(sf::RenderWindow& window);

        bool checkDeath();

        bool checkSurvive();

    private:
        int lane;
        int speed = 100;
        int health = 100;
        bool survive = false;

        float postDeathTime;
        sf::Clock postDeathClock;

        int lane2 = 422;
        int lane3 = 508;
        int lane4 = 594;

};

#endif
