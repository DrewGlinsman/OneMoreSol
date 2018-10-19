#include <SFML/Graphics.hpp>
#include "GameViewPlayer.h"
#include "GameViewMenu.h"
#include "GameLogic.h"

using namespace std;

int main(int argc, char** argv)
{

    sf::Event Event; // Process events

    string currentWinner;

    bool gameOver = false; // Never gets set to true
    bool quit = false; // Checks to see if player quit

    while(!gameOver) // Start game loop
    {
        GameViewMenu* currentMenu = new GameViewMenu(); //Create menu window for player

        quit = currentMenu -> gameViewMenuIsOpen();

        if(quit == true)
        {
            return 0;
        }

        delete currentMenu; // Contain any memory leaks

        // # of players has been determined and the game is starting

        //--------------------------------------------------------------------------------------

        GameViewPlayer* currentGame = new GameViewPlayer(); // Create player window

        sf::Clock clock; // Game loop clock

        float delta; // Time between game loops

        int x = 0;
        GameLogic logic;
        while(x < 100)
        {
            logic.selectKorat(delta);
            x++;
        }


        quit = currentGame -> playerViewIsOpen();

        if (quit == true)
        {
            return 0;
        }

        delta = clock.getElapsedTime().asSeconds(); // Gets clock time between loops

        clock.restart();  // Resets game clock between loops

    }
}
