#include "TextureLoader.h"
#include <iostream>

TextureLoader::TextureLoader()//shouldn't do the loading as can't allow failure
{
    load();
}

void TextureLoader::load()
{
    if (!mtSpriteSheet.loadFromFile("assets/mtSpriteSheet.png"))
        std::cout << "Failed to Load mtSpriteSheet." << std::endl;

    mtSpriteSheet.setSmooth(true);
}
