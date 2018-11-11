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

    if (!soundTrack[2].loadFromFile("assets/Level_3_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 3 music into soundTrack." << std::endl;

    if (!soundTrack[3].loadFromFile("assets/Level_4_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 4 Music into soundTrack." << std::endl;

    if (!soundTrack[4].loadFromFile("assets/Level_5_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 5 music into soundTrack." << std::endl;

    if (!soundTrack[5].loadFromFile("assets/Level_6_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 6 Music into soundTrack." << std::endl;

    if (!soundTrack[6].loadFromFile("assets/Level_7_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 7 music into soundTrack." << std::endl;

    if (!soundTrack[7].loadFromFile("assets/Level_8_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 8 Music into soundTrack." << std::endl;

    if (!soundTrack[8].loadFromFile("assets/Level_9_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 9 music into soundTrack." << std::endl;

    if (!soundTrack[9].loadFromFile("assets/Level_10_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 10 Music into soundTrack." << std::endl;

    if (!soundTrack[10].loadFromFile("assets/Level_11_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 11 music into soundTrack." << std::endl;

    if (!soundTrack[11].loadFromFile("assets/Level_12_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 12 Music into soundTrack." << std::endl;

    if (!soundTrack[12].loadFromFile("assets/Level_13_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 13 music into soundTrack." << std::endl;

    if (!soundTrack[13].loadFromFile("assets/Level_14_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 14 Music into soundTrack." << std::endl;

    if (!soundTrack[14].loadFromFile("assets/Level_15_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 15 music into soundTrack." << std::endl;

    if (!soundTrack[15].loadFromFile("assets/Level_16_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 16 Music into soundTrack." << std::endl;

    if (!soundTrack[16].loadFromFile("assets/Level_17_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 17 music into soundTrack." << std::endl;

    if (!soundTrack[17].loadFromFile("assets/Level_18_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 18 Music into soundTrack." << std::endl;

    if (!soundTrack[18].loadFromFile("assets/Level_19_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 19 music into soundTrack." << std::endl;

    if (!soundTrack[19].loadFromFile("assets/Level_20_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 20 Music into soundTrack." << std::endl;

}
