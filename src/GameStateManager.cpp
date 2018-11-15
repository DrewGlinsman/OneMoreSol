#include "GameStateManager.h"

GameStateManager::GameStateManager()
: gameWindow(sf::VideoMode(1440, 900, 32), "One More Sol",sf::Style::Titlebar | sf::Style::Close)

{
    initialize();
}

void GameStateManager::initialize()
{
    if(!loadScreenTexture.loadFromFile("assets/loadingScreen.png"))
        std::cout<<"Failed to load loading screen." << std::endl;
    loadScreen.setOrigin(0,900);
    loadScreen.setPosition(0,900);
    loadScreen.setSize(sf::Vector2f(1440,900));
    loadScreen.setTexture(&loadScreenTexture);
    gameWindow.draw(loadScreen);
    gameWindow.display();
    playView = new GameViewPlayer();
}

bool GameStateManager::gameViewIsOpen()
{
    bool quit;

    if (currentState == "Start")
    {
        quit = playView -> menuViewIsOpen(gameWindow);
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
