
#ifndef TANKBOSS_H
#define TANKBOSS_H

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

using namespace std;

class TankBoss {

    private:

    public:
        sf::Sprite tankBoss;

        sf::Texture mtSpriteSheet;//this is a second load, loaded also on gameviewplayer. how to expand scope?

        TankBoss(TextureLoader*);
};

#endif
