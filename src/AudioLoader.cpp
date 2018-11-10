#include "AudioLoader.h"
#include <iostream>

AudioLoader::AudioLoader()
{
    if (!mtSpriteSheet.loadFromFile("assets/mtSpriteSheet.png"))
        std::cout << "Failed to Load mtSpriteSheet." << std::endl;

    mtSpriteSheet.setSmooth(true);
}
