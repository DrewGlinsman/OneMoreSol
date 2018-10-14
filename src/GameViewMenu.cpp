//This is where the player views what happens onscreen.

#include "GameViewMenu.h"
#include "GameViewPlayer.h"
#include "Gun.h"

using namespace std;

GameViewMenu::GameViewMenu() // Menu window constructor
    : menuWindow(sf::VideoMode(1440, 900, 32), "One More Soul",sf::Style::Titlebar | sf::Style::Close)
{
    if (!menuImage.loadFromFile("assets/menuScreen.png"))
        cout << "Could not load requested image." << endl;
    if (!playBtnImg.loadFromFile("assets/playButton.png"))
        cout << "Could not load requested image." << endl;
    if (!playBtnHImg.loadFromFile("assets/playButtonH.png"))
        cout << "Could not load requested image." << endl;
    if (!storyBtnImg.loadFromFile("assets/storyButton.png"))
        cout << "Could not load requested image." << endl;
    if (!storyBtnHImg.loadFromFile("assets/storyButtonH.png"))
        cout << "Could not load requested image." << endl;
    if (!exitBtnImg.loadFromFile("assets/exitButton.png"))
        cout << "Could not load requested image." << endl;
    if (!exitBtnHImg.loadFromFile("assets/exitButtonH.png"))
        cout << "Could not load requested image." << endl;

    if (!menuSound.loadFromFile("assets/Menu_Music.ogg"))
        cout << "Could not load request music." << endl;

    //selector.setPosition(0,0);
    //cout << "0,0" << endl;
    background.setSize(sf::Vector2f(1,1));

    background.setPosition(0,0);
    background.setSize(sf::Vector2f(1440,900));
    background.setTexture(&menuImage);

    playBtnRec.setOrigin((1308/2),0);
    playBtnRec.setPosition(1440,400);
    playBtnRec.setSize(sf::Vector2f((1308/2),(224/2)));
    playBtnRec.setTexture(&playBtnImg);
    playBtnHRec.setOrigin(1308,0);
    playBtnHRec.setPosition(1440,400);
    playBtnHRec.setSize(sf::Vector2f(1308,224));
    playBtnHRec.setTexture(&playBtnHImg);

    storyBtnRec.setOrigin((1050/2),0);
    storyBtnRec.setPosition(1440,530);
    storyBtnRec.setSize(sf::Vector2f((1050/2),(117/2)));
    storyBtnRec.setTexture(&storyBtnImg);
    storyBtnHRec.setPosition(486,401);
    storyBtnHRec.setSize(sf::Vector2f(1050,117));
    storyBtnHRec.setTexture(&storyBtnHImg);

    exitBtnRec.setOrigin((444),0);
    exitBtnRec.setPosition(1440,605);
    exitBtnRec.setSize(sf::Vector2f(444,(117/2)));
    exitBtnRec.setTexture(&exitBtnImg);
    exitBtnHRec.setPosition(486,501);
    exitBtnHRec.setSize(sf::Vector2f(888,117));
    exitBtnHRec.setTexture(&exitBtnHImg);


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
    menuWindow.draw(playBtnRec);
    menuWindow.draw(storyBtnRec);
    menuWindow.draw(exitBtnRec);

    // display
    menuWindow.display();
}
