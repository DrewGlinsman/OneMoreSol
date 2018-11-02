#include "GameStateManager.h"

GameStateManager::GameStateManager()
: gameWindow(sf::VideoMode(1440, 900, 32), "One More Sol",sf::Style::Titlebar | sf::Style::Close)

{
    menuView = new GameViewMenu();
    playView = new GameViewPlayer();
}

bool GameStateManager::gameViewIsOpen()
{
    if (currentState == "Start")
    {
        menuView -> gameViewIsOpen(gameWindow);
    }
    if (currentState == "Play")
    {
        playView -> gameViewIsOpen(gameWindow);
    }
}

void GameStateManager::setState(std::string state)
{
    currentState = state;
}
