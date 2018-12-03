#ifndef AUDIOLOADER_H
#define AUDIOLOADER_H

#include <SFML/Audio.hpp>
class AudioLoader
{
private:

public:
    AudioLoader();
    void load();
    std::array<sf::SoundBuffer, 39> soundTrack; //needs to be larger to hold sound effects too
};
#endif
