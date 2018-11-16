#include <SFML/Graphics.hpp>
#include "GameViewPlayer.h"
#include "GameViewMenu.h"
#include "GameLogic.h"
#include "GameStateManager.h"

using namespace std;

int main(int argc, char** argv)
{

    //sf::Event Event; // Process events

    string currentWinner;

    bool gameOver = false; // Never gets set to true
    bool quit = false; // Checks to see if player quit
    bool gameStarted = false;

    GameStateManager* currentGameWindow = new GameStateManager();

    while(!gameOver) // Start game loop
    {
         //Create menu window for player

        if(!gameStarted)
        {
            currentGameWindow -> setState("Start");

            quit = currentGameWindow -> gameViewIsOpen();

            if(quit == true)
            {
                return 0;
            }
        }

        gameStarted = true;

        currentGameWindow -> setState("Play");

        // # of players has been determined and the game is starting

        //--------------------------------------------------------------------------------------

        sf::Clock clock; // Game loop clock

        float delta; // Time between game loops

        quit = currentGameWindow -> gameViewIsOpen();

        if (quit == true)
        {
            return 0;
        }

        delta = clock.getElapsedTime().asSeconds(); // Gets clock time between loops

        currentGameWindow -> setState("Lost");

        quit = currentGameWindow -> gameViewIsOpen();

        if (quit == true)
        {
            return 0;
        }

        clock.restart();  // Resets game clock between loops

    }
}
