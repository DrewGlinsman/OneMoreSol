#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include <SFML/Graphics.hpp>
class TextureLoader
{
private:

public:
    TextureLoader();
    sf::Texture mtSpriteSheet;
    void load();
    std::array<sf::Texture, 16> textureArray;
};
#endif
