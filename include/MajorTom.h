
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

using namespace std;

class MajorTom {

    private:
        float positionX;
        float positionY;
        float newPosition;
        float timePassed;
        int currentHealth;
        int newHealth;

        Gun* pistol = new PlasmaPistol();
        Gun* shotgun = new PlasmaShotgun();
        Gun* rifle = new LaserRifle();
        Gun* minigun = new LaserMinigun();
        Gun* thrower = new ArcThrower();
        Gun* sniper = new GaussRifle();
        Gun* bigFunGun = new BFG();

    public:
        sf::Sprite majorTom;
        sf::Texture mtPlasmaPistol;
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

        int getHealth();

        void setHealth(int newHealth);

        Gun getGun();

        void setGun(int gunNumber);

        bool checkDeath();

        void updateGame(sf::RenderWindow& gameWindow);

};

#endif
