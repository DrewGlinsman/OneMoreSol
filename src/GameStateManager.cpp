#include "GameStateManager.h"

GameStateManager::GameStateManager()
: gameWindow(sf::VideoMode(1440, 900, 32), "One More Sol",sf::Style::Titlebar | sf::Style::Close)

{
    initialize();
}

void GameStateManager::initialize()
{
    playView = new GameViewPlayer();
}

bool GameStateManager::gameViewIsOpen()
{
    bool quit;
    menuView = new GameViewMenu();
    if (currentState == "Start")
    {
        quit = menuView -> gameViewIsOpen(gameWindow);
        return quit;
    }
    if (currentState == "Play")
    {
        quit = playView -> gameViewIsOpen(gameWindow);
        return quit;
    }

    if (currentState == "Lost")
    {
        quit = playView -> lossViewIsOpen(gameWindow);
        return quit;
    }

}

void GameStateManager::setState(std::string state)
{
    currentState = state;
}
