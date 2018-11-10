#include "AudioLoader.h"
#include <iostream>

AudioLoader::AudioLoader()
{
    load();
}

void AudioLoader::load()
{
    if (!soundTrack[0].loadFromFile("assets/Level_1_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 1 music into soundTrack." << std::endl;

    if (!soundTrack[1].loadFromFile("assets/Level_2_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 2 Music into soundTrack." << std::endl;

}
