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
    bool gameRestarted = false;

    GameStateManager* currentGameWindow = new GameStateManager();

    while(!gameOver) // Start game loop
    {
         //Create menu window for player

        if(!gameStarted || gameRestarted)
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
        cout << "Entering Play View" << endl;

        quit = currentGameWindow -> gameViewIsOpen();
        gameRestarted = !quit;

        if (quit == true)
        {
            return 0;
        }

        currentGameWindow -> setState("Lost");

        gameRestarted = currentGameWindow -> gameViewIsOpen();

    }
}
