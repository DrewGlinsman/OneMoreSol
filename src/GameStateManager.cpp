#include "GameStateManager.h"

GameStateManager::GameStateManager()
: gameWindow(sf::VideoMode(1440, 900, 32), "One More Sol",sf::Style::Titlebar | sf::Style::Close)

{

}

bool GameStateManager::gameViewIsOpen()
{
    bool quit;
    if (currentState == "Start")
    {
        menuView = new GameViewMenu();
        quit = menuView -> gameViewIsOpen(gameWindow);
        return quit;
    }
    if (currentState == "Play")
    {
        playView = new GameViewPlayer();
        quit = playView -> gameViewIsOpen(gameWindow);
        return quit;
    }
}

void GameStateManager::setState(std::string state)
{
    currentState = state;
}
