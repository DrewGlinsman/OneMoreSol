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

    while(!gameOver) // Start game loop
    {
        GameViewMenu* currentMenu = new GameViewMenu(); //Create menu window for player

        currentMenu -> menuWindow.display();

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
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    currentMenu -> menuWindow.close();
        }

        delete currentMenu; // Contain any memory leaks

        // # of players has been determined and the game is starting

        //--------------------------------------------------------------------------------------

        GameViewPlayer* currentGame = new GameViewPlayer(); // Create player window

        sf::Clock clock; // Game loop clock

        float delta; // Time between game loops

        currentGame -> updateGame();

        currentGame -> gameWindow.display();

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
