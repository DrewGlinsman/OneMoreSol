
#ifndef GAMEVIEWPLAYER_H
#define GAMEVIEWPLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <typeinfo>
#include "Gun.h"
#include "MajorTom.h"
#include "GameLogic.h"
#include "TextureLoader.h"

using namespace std;

class GameViewPlayer
{

private:
    float timePassed;

public:
    sf::Font gameFont;
    const int iconScale = 64;

    sf::RenderWindow gameWindow;
    sf::RectangleShape background;
    sf::CircleShape sky;

    sf::Sprite weapon1;
    sf::Sprite weapon2;
    sf::Sprite weapon3;
    sf::Sprite weapon4;
    sf::Sprite weapon5;
    sf::Sprite weapon6;
    sf::Sprite weapon7;

    sf::Texture gameImage;
    sf::Texture playerImage;
    sf::Texture gameSky;
    sf::Texture lockIcon;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;

    sf::SoundBuffer gameSound;
    sf::Sound gameMusic;
    sf::Text survivorCnt;
    sf::Event Event;

    GameLogic* logic;

    MajorTom* majorTom;//need to make new and non default constructor

    TextureLoader* loadedTextures;

    GameViewPlayer();
    bool playerViewIsOpen();
    void updateGame(void);

};

#endif
