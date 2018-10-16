#include "GameViewPlayer.h"
#include <iostream>

using namespace std;

GameViewPlayer::GameViewPlayer() // Player window constructor
    : gameWindow(sf::VideoMode(1440, 900, 32), "One More Sol",sf::Style::Titlebar | sf::Style::Close)
{
    if(!gameFont.loadFromFile("assets/Game_Font.ttf"))
        cout << "Could not load requested font." << endl;

    if (!gameSound.loadFromFile("assets/Gamex_Music.ogg"))
        cout << "Could not load request music." << endl;

    if (!gameImage.loadFromFile("assets/playField.png"))
        cout << "Could not load requested image." << endl;

    if (!gameSky.loadFromFile("assets/skyBox.png"))
        cout << "Failed to Load Skybox." << endl;

    sky.setRadius(894);
    sky.setOrigin(894,894);
    sky.setPosition(720, 450);
    sky.setTexture(&gameSky);

    background.setOrigin(0,724);
    background.setPosition(0,900);                    // Applies textures to ball, paddles and background
    background.setSize(sf::Vector2f(1440,724));
    background.setTexture(&gameImage);

    gameMusic.setBuffer(gameSound);
    gameMusic.play();
    gameMusic.setLoop(true);

}

bool GameViewPlayer::playerViewIsOpen()
{
    sf::Clock clock; // Game loop clock
    float delta; // Time between game loops
    updateGame();
    while(gameWindow.isOpen())
    {
        delta = clock.getElapsedTime().asSeconds(); // Gets clock time between loops
         while(gameWindow.pollEvent(Event))
            {
                if(Event.type == sf::Event::Closed)
                {
                    gameWindow.close(); // Quit game
                    return true;
                }
                if(Event.type == sf::Event::KeyPressed)
                {
                    if(Event.key.code == sf::Keyboard::Escape)
                    {
                        gameWindow.close();
                        return true;
                    }
                    if(Event.key.code == sf::Keyboard::Up)
                    {
                        majorTom.moveTomUp(delta);
                    }
                    if(Event.key.code == sf::Keyboard::Down)
                    {
                        majorTom.moveTomDown(delta);
                    }
                }
            }
        clock.restart();  // Resets game clock between loops
    }
    return false;
}

void GameViewPlayer::movePlayer(float timePassed)
{

}

void GameViewPlayer::moveEnemy(float timePassed)
{

}

void GameViewPlayer::updateGame(void) // Draws all elements of screen
{

    gameWindow.clear(sf::Color::Black);
    majorTom.drawTom(gameWindow);
    gameWindow.draw(sky);
    gameWindow.draw(background);

    gameWindow.display();
}

void GameViewPlayer::deleteObjects(void)
{
    delete currentPlayer;
}
