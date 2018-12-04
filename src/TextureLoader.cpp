#include "TextureLoader.h"
#include <iostream>

/** \brief Constructor for TextureLoader calls load() function.
 *
 * \param accepts no parameters
 * \return returns nothing
 *
 */
TextureLoader::TextureLoader()//shouldn't do the loading as can't allow failure
{
    load();
}

/** \brief Loads the game textures into an array of textures.
 *
 * \param accepts no parameters
 * \return returns nothing
 *
 */
void TextureLoader::load()
{
    if (!textureArray[0].loadFromFile("../assets/mtSpriteSheet.png"))
        std::cout << "Failed to Load mtSpriteSheet." << std::endl;

    if (!textureArray[1].loadFromFile("../assets/playField.png"))
        std::cout << "Could not load playField." << std::endl;

    if (!textureArray[2].loadFromFile("../assets/skyBox.png"))
        std::cout << "Failed to Load Skybox." << std::endl;

    if (!textureArray[3].loadFromFile("../assets/lockIcon.png"))
        std::cout << "Failed to Load Lock Icon." << std::endl;

    if (!textureArray[4].loadFromFile("../assets/menuScreen.png"))
        std::cout << "Failed to Load menuScreen." << std::endl;

    if (!textureArray[5].loadFromFile("../assets/playButton.png"))
        std::cout << "Failed to Load playButton." << std::endl;

    if (!textureArray[6].loadFromFile("../assets/playButtonH.png"))
        std::cout << "Failed to Load playButtonH." << std::endl;

    if (!textureArray[7].loadFromFile("../assets/storyButton.png"))
        std::cout << "Failed to Load storyButton." << std::endl;

    if (!textureArray[8].loadFromFile("../assets/storyButtonH.png"))
        std::cout << "Failed to Load storyButtonH." << std::endl;

    if (!textureArray[9].loadFromFile("../assets/exitButton.png"))
        std::cout << "Failed to Load exitButton." << std::endl;

    if (!textureArray[10].loadFromFile("../assets/exitButtonH.png"))
        std::cout << "Failed to Load exitButtonH." << std::endl;

    if (!textureArray[11].loadFromFile("../assets/lossScreen.png"))
        std::cout << "Failed to Load lossScreen." << std::endl;

    if (!textureArray[12].loadFromFile("../assets/retryButton.png"))
        std::cout << "Failed to Load retryButton." << std::endl;

    if (!textureArray[13].loadFromFile("../assets/retryButtonH.png"))
        std::cout << "Failed to Load retryButtonH." << std::endl;

    if (!textureArray[14].loadFromFile("../assets/endButton.png"))
        std::cout << "Failed to Load endButton." << std::endl;

    if (!textureArray[15].loadFromFile("../assets/endButtonH.png"))
        std::cout << "Failed to Load endButtonH." << std::endl;

    if (!textureArray[16].loadFromFile("../assets/nightLayer.png"))
        std::cout << "Failed to Load nightLayer." << std::endl;

    if(!textureArray[17].loadFromFile("../assets/winScreen.png"))
        std::cout << "Failed to Load Win Screen" << std::endl;

    if(!textureArray[18].loadFromFile("../assets/storyScreen.png"))
        std::cout << "Failed to Load Story Screen" << std::endl;

    if(!textureArray[19].loadFromFile("../assets/menuButton.png"))
        std::cout << "Failed to Load menu Button" << std::endl;

    if(!textureArray[20].loadFromFile("../assets/menuButtonH.png"))
        std::cout << "Failed to Load menuButtonH" << std::endl;

    if(!textureArray[21].loadFromFile("../assets/winButton.png"))
        std::cout << "Failed to Load Win button" << std::endl;

    if(!textureArray[22].loadFromFile("../assets/winButtonH.png"))
        std::cout << "Failed to Load Win buttonH" << std::endl;

    if(!textureArray[23].loadFromFile("../assets/controlScreen.png"))
        std::cout << "Failed to Load Control Screen" << std::endl;

    //goes through the textureArray and "anti-alias"es them.
    for(int i = 0; i < textureArray.size(); ++i)
    {
        textureArray[i].setSmooth(true);
    }
}
