#include "AudioLoader.h"
#include <iostream>

/** \brief Constructor for AudioLoader calls load() function.
 *
 * \param accepts no parameters
 * \return returns nothing
 *
 */
AudioLoader::AudioLoader()
{
    load();
}

/** \brief Loads the game audio into a sound track array of buffers.
 *
 * \param accepts no parameters
 * \return returns nothing
 *
 */
void AudioLoader::load()
{
    //soundTrack is size 20. one song for each level, but more should be added
    //to hold sound effects starting at index 20.
    if (!soundTrack[0].loadFromFile("assets/Level_1_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 1 music into soundTrack." << std::endl;

    if (!soundTrack[1].loadFromFile("assets/Level_2_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 2 Music into soundTrack." << std::endl;

}
