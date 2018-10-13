// Chris Wolinski SFML Pong

//This is where the player views what happens onscreen.

#include "GameViewMenu.h"

using namespace std;

     GameViewMenu::GameViewMenu() // Menu window constructor
     : menuWindow(sf::VideoMode(1440, 900, 32), "One More Soul",sf::Style::Titlebar | sf::Style::Close)
     {
        if(!menuFont.loadFromFile("assets/Game_Font.ttf"))       // Constructor loads and sets all items on screen
            cout << "Could not load requested font." << endl;

        if (!menuImage.loadFromFile("assets/Menu_Screen.png"))
           cout << "Could not load requested image." << endl;

        if (!menuSound.loadFromFile("assets/Menu_Music.ogg"))
            cout << "Could not load request music." << endl;

        background.setPosition(0,0);
        background.setSize(sf::Vector2f(1440,900));
        background.setTexture(&menuImage);

        menuTitle.setFont(menuFont);
        menuTitle.setCharacterSize(75);
        menuTitle.setColor(sf::Color::Black);
        menuTitle.setPosition(titleX,titleY);
        menuTitle.setString("Pong");

        menuPlay1.setFont(menuFont);
        menuPlay1.setCharacterSize(25);
        menuPlay1.setColor(sf::Color::White);
        menuPlay1.setPosition(playX1,playY1);
        menuPlay1.setString("Press 1 To PLAY with 1 Player");

        menuPlay2.setFont(menuFont);
        menuPlay2.setCharacterSize(25);
        menuPlay2.setColor(sf::Color::White);
        menuPlay2.setPosition(playX2,playY2);
        menuPlay2.setString("Press 2 To PLAY with 2 Players");

        menuPlay3.setFont(menuFont);
        menuPlay3.setCharacterSize(25);
        menuPlay3.setColor(sf::Color::White);
        menuPlay3.setPosition(playX3,playY3);
        menuPlay3.setString("Controls P1:(W/S) P2:(Up/Down)");

        menuPlay4.setFont(menuFont);
        menuPlay4.setCharacterSize(25);
        menuPlay4.setColor(sf::Color::Cyan);
        menuPlay4.setPosition(playX4,playY4);
        menuPlay4.setString("(W/S)");

        menuPlay5.setFont(menuFont);
        menuPlay5.setCharacterSize(25);
        menuPlay5.setColor(sf::Color::Magenta);
        menuPlay5.setPosition(playX5,playY5);
        menuPlay5.setString("(Up/Down)");

    }

    bool GameViewMenu::menuSelection()
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) // End menu loop and set player count
        {
            menuWindow.close();
            return false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            menuWindow.close();
            return true;
        }
    }

    void GameViewMenu::updateMenu(void) // Updates screen
    {
        menuMusic.setBuffer(menuSound);

        menuMusic.play();

        menuMusic.setLoop(true);

        menuWindow.clear(sf::Color::Black);

        menuWindow.draw(background);

        menuWindow.draw(menuTitle);

        menuWindow.draw(menuPlay1);

        menuWindow.draw(menuPlay2);

        menuWindow.draw(menuPlay3);

        menuWindow.draw(menuPlay4);

        menuWindow.draw(menuPlay5);

        // display
        menuWindow.display();
   }




