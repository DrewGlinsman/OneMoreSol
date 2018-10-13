// Chris Wolinski SFML Pong

// Location of main loop and keyboard input

#include <SFML/Graphics.hpp>
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

            twoPlayerGame = currentMenu -> menuSelection(); // Determines # of players

        }

        delete currentMenu; // Contain any memory leaks

    }
}

        // # of players has been determined and the game is starting

        //--------------------------------------------------------------------------------------

