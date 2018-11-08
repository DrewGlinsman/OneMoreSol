// Chris Wolinski

#include "BikeBoss.h"
#include <iostream>

using namespace std;

BikeBoss::BikeBoss(TextureLoader* loadedTextures)
{

}

void BikeBoss::drawBoss(sf::RenderWindow& window)
{
    window.draw(bikeBoss);
}
