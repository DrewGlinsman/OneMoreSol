
#ifndef TANKBOSS_H
#define TANKBOSS_H

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

using namespace std;

class TankBoss {

    private:

    public:
        sf::Sprite tankBoss;

        TankBoss(TextureLoader*);

        void drawBoss(sf::RenderWindow& window);
};

#endif
