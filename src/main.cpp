#include <SFML/Graphics.hpp>
#include "GameViewPlayer.h"
#include "GameViewMenu.h"

using namespace std;

int main(int argc, char** argv)
{

    sf::Event Event; // Process events

    string currentWinner;

    bool gameOver = false; // Never gets set to true
    bool twoPlayerGame = false;
    bool quit = false;
    sf::Event event;
    while(!gameOver) // Start game loop
    {
        GameViewMenu* currentMenu = new GameViewMenu(); //Create menu window for player

        currentMenu -> menuWindow.display();
        sf::RectangleShape selector;
        selector.setPosition(0,0);
        cout << "0,0" << endl;
        currentMenu -> updateMenu();

        while(currentMenu -> menuWindow.isOpen()) // Menu loop
        {
            while(currentMenu -> menuWindow.pollEvent(Event))
            {
                if(Event.type == sf::Event::Closed)
                {
                    currentMenu -> menuWindow.close(); // Quit game
                    return 0;
                }

                if(Event.type == sf::Event::KeyPressed)
                {
                    if(Event.key.code == sf::Keyboard::Up)
                    {
                        if(sf::Vector2f (0,0) == selector.getPosition())
                        {
                            selector.setPosition(0,2);
                            currentMenu -> selectButton(0,2);
                            cout << "0,2" << endl;
                        }
                        else if(sf::Vector2f (0,1) == selector.getPosition())
                        {
                            selector.setPosition(0,0);
                            currentMenu -> selectButton(0,0);
                            cout << "0,0" << endl;
                        }
                        else if(sf::Vector2f (0,2) == selector.getPosition())
                        {
                            selector.setPosition(0,1);
                            currentMenu -> selectButton(0,1);
                            cout << "0,1" << endl;
                        }
                    }

                    if(Event.key.code == sf::Keyboard::Down)
                    {
                        if(sf::Vector2f (0,0) == selector.getPosition())
                        {
                            selector.setPosition(0,1);
                            currentMenu -> selectButton(0,1);
                            cout << "0,1" << endl;
                        }
                        else if(sf::Vector2f (0,1) == selector.getPosition())
                        {
                            selector.setPosition(0,2);
                            currentMenu -> selectButton(0,2);
                            cout << "0,2" << endl;
                        }
                        else if(sf::Vector2f (0,2) == selector.getPosition())
                        {
                            selector.setPosition(0,0);
                            currentMenu -> selectButton(0,0);
                            cout << "0,0" << endl;
                        }
                    }

                    if(Event.key.code == sf::Keyboard::Space || Event.key.code == sf::Keyboard::Enter)
                    {
                        if(sf::Vector2f (0,0) == selector.getPosition())
                        {
                            currentMenu -> menuWindow.close();
                        }
                        if(sf::Vector2f (0,1) == selector.getPosition())
                        {
                            currentMenu -> menuWindow.close();
                        }
                        if(sf::Vector2f (0,2) == selector.getPosition())
                        {
                            currentMenu -> menuWindow.close();
                            return 0;
                        }
                    }
                }
            }
        }

        delete currentMenu; // Contain any memory leaks

        // # of players has been determined and the game is starting

        //--------------------------------------------------------------------------------------

        GameViewPlayer* currentGame = new GameViewPlayer(); // Create player window

        sf::Clock clock; // Game loop clock

        float delta; // Time between game loops

        currentGame -> updateGame();

        while(currentGame -> gameWindow.isOpen()) // Game loop
        {
            while(currentGame -> gameWindow.pollEvent(Event))
            {
                if(Event.type == sf::Event::Closed)
                {
                    currentGame -> gameWindow.close(); // Quit game
                    return 0;
                }
            }

            delta = clock.getElapsedTime().asSeconds(); // Gets clock time between loops

            clock.restart();  // Resets game clock between loops
        }
    }
}
