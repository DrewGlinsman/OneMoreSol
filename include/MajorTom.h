
#ifndef MAJORTOM_H
#define MAJORTOM_H

#include <SFML/Graphics.hpp>
#include "Gun.h"
#include "PlasmaPistol.h"
#include "PlasmaShotgun.h"
#include "LaserRifle.h"
#include "LaserMinigun.h"
#include "ArcThrower.h"
#include "GaussRifle.h"
#include "BFG.h"
#include "TextureLoader.h"

using namespace std;

class MajorTom {

    private:
        float positionX;
        float positionY;
        float newPosition;
        float timePassed;
        int currentHealth;
        int newHealth;
        int survivorCnt;

    public:
        sf::Sprite majorTom;

        sf::Texture mtSpriteSheet;//this is a second load, loaded also on gameviewplayer. how to expand scope?

        sf::Sprite mtStandPPistol;

        Gun* pistol = new PlasmaPistol();
        Gun* shotgun = new PlasmaShotgun();
        Gun* rifle = new LaserRifle();
        Gun* minigun = new LaserMinigun();
        Gun* thrower = new ArcThrower();
        Gun* sniper = new GaussRifle();
        Gun* bigFunGun = new BFG();

        int currentGun = 1;

        MajorTom(TextureLoader*);

        void drawTom(sf::RenderWindow& window);

        float getTomPosition();
        void setTomPositionX(float);
        void setTomPositionY(float);

        bool initMove(float, string);

        bool keepMoving(float, string);

        int getHealth();
        void setHealth(int);

        void shoot(float);

        int getGun();
        void setGun(int);

        int getSurvivors();
        void setSurvivors(int);

        bool checkDeath();

        void updateGame(sf::RenderWindow& gameWindow);

};

#endif
