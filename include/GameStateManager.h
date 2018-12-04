#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameViewPlayer.h"

using namespace std;

class GameStateManager
{
public:
    sf::RectangleShape loadScreen;
    sf::Texture loadScreenTexture;
    sf::RenderWindow gameWindow;
    GameViewPlayer* playView;
    std::string currentState;
    GameStateManager();
    virtual bool gameViewIsOpen();
    void setState(std::string state);
    void initialize();
};
