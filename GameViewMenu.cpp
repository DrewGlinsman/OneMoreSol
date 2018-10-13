//This is where the player views what happens onscreen.

#include "GameViewMenu.h"

using namespace std;

     GameViewMenu::GameViewMenu() // Menu window constructor
     : menuWindow(sf::VideoMode(1440, 900, 32), "One More Soul",sf::Style::Titlebar | sf::Style::Close)
     {
        if (!menuImage.loadFromFile("assets/Menu_Screen.png"))
           cout << "Could not load requested image." << endl;

        if (!menuSound.loadFromFile("assets/Menu_Music.ogg"))
            cout << "Could not load request music." << endl;

        //selector.setPosition(0,0);
        //cout << "0,0" << endl;
        background.setSize(sf::Vector2f(1,1));

        background.setPosition(0,0);
        background.setSize(sf::Vector2f(1440,900));
        background.setTexture(&menuImage);


        menuMusic.setBuffer(menuSound);

        menuMusic.play();

        menuMusic.setLoop(true);


    }

    /*
    bool GameViewMenu::menuSelection()
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !buttonHeld) // End menu loop and set player count
        {
            if(sf::Vector2f (0,0) == selector.getPosition())
            {
                selector.setPosition(0,2);
                cout << "0,2" << endl;
            }
            else if(sf::Vector2f (0,1) == selector.getPosition())
            {
                selector.setPosition(0,0);
                cout << "0,0" << endl;
            }
            else if(sf::Vector2f (0,2) == selector.getPosition())
            {
                selector.setPosition(0,1);
                cout << "0,1" << endl;
            }

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !buttonHeld)
        {
            if(sf::Vector2f (0,0) == selector.getPosition())
            {
                selector.setPosition(0,1);
                cout << "0,1" << endl;
            }
            else if(sf::Vector2f (0,1) == selector.getPosition())
            {
                selector.setPosition(0,2);
                cout << "0,2" << endl;
            }
            else if(sf::Vector2f (0,2) == selector.getPosition())
            {
                selector.setPosition(0,0);
                cout << "0,0" << endl;
            }

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if(sf::Vector2f (0,0) == selector.getPosition())
            {

            }
            if(sf::Vector2f (0,1) == selector.getPosition())
            {

            }
            if(sf::Vector2f (0,2) == selector.getPosition())
            {

            }
        }
    }

    */

    void GameViewMenu::updateMenu(void) // Updates screen
    {

        menuWindow.clear(sf::Color::Black);

        menuWindow.draw(background);

        // display
        menuWindow.display();
   }
