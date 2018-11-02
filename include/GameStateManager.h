#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameViewPlayer.h"
#include "GameViewMenu.h"

using namespace std;

class GameStateManager
{
public:
    sf::RenderWindow gameWindow;
    GameViewPlayer* playView;
    GameViewMenu* menuView;
    std::string currentState;
    GameStateManager();
    virtual bool gameViewIsOpen();
    void setState(std::string state);
};
