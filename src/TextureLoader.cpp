#include "TextureLoader.h"
#include <iostream>

TextureLoader::TextureLoader()
{
    if (!mtSpriteSheet.loadFromFile("assets/mtSpriteSheet.png"))
        std::cout << "Failed to Load mtSpriteSheet." << std::endl;

    mtSpriteSheet.setSmooth(true);
}
