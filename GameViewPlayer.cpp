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

        if (!gameImage.loadFromFile("assets/Game_Screen.png"))
            cout << "Could not load requested image." << endl;

        background.setPosition(0,0);                    // Applies textures to ball, paddles and background
        background.setSize(sf::Vector2f(1440,900));
        background.setTexture(&gameImage);

        gameMusic.setBuffer(gameSound);
        gameMusic.play();
        gameMusic.setLoop(true);

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

        gameWindow.draw(background);

        gameWindow.display();
   }

   void GameViewPlayer::deleteObjects(void)
   {
       delete currentPlayer;
   }
