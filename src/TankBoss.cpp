// Chris Wolinski

#include "TankBoss.h"
#include <iostream>

using namespace std;

TankBoss::TankBoss(TextureLoader* loadedTextures)
{
    tankBoss.setTexture(loadedTextures->mtSpriteSheet);
    tankBoss.setTextureRect(sf::IntRect(640,256,192,192));
    tankBoss.setOrigin(sf::Vector2f(96.f,96.f));
    tankBoss.setScale(1.2f,1.2f);
}

void TankBoss::drawBoss(sf::RenderWindow& window)
{
    window.draw(tankBoss);
}
