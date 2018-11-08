
#ifndef BIKEBOSS_H
#define BIKEBOSS_H

#include <SFML/Graphics.hpp>
#include "TextureLoader.h"

using namespace std;

class BikeBoss {

    private:

    public:
        sf::Sprite bikeBoss;

        sf::Texture mtSpriteSheet;//this is a second load, loaded also on gameviewplayer. how to expand scope?

        BikeBoss(TextureLoader*);

        void drawBoss(sf::RenderWindow& window);
};

#endif
