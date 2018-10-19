#include "GameViewPlayer.h"
#include <iostream>
#include <typeinfo>

using namespace std;

GameViewPlayer::GameViewPlayer() // Player window constructor
    : gameWindow(sf::VideoMode(1440, 900, 32), "One More Sol",sf::Style::Titlebar | sf::Style::Close)
{
    if(!gameFont.loadFromFile("assets/impact.ttf"))
        cout << "Could not load requested font." << endl;

    if (!gameSound.loadFromFile("assets/Gamex_Music.ogg"))
        cout << "Could not load request music." << endl;

    if (!gameImage.loadFromFile("assets/playField.png"))
        cout << "Could not load requested image." << endl;

    if (!gameSky.loadFromFile("assets/skyBox.png"))
        cout << "Failed to Load Skybox." << endl;

    if (!lockIcon.loadFromFile("assets/lockIcon.png"))
        cout << "Failed to Load Lock Icon." << endl;

    sky.setRadius(894);
    sky.setOrigin(894,894);
    sky.setPosition(720, 450);
    sky.setTexture(&gameSky);

    background.setOrigin(0,724);
    background.setPosition(0,900);
    background.setSize(sf::Vector2f(1440,724));
    background.setTexture(&gameImage);


    weapon1.setSize(sf::Vector2f(iconScale,iconScale));
    weapon2.setSize(sf::Vector2f(iconScale,iconScale));
    weapon3.setSize(sf::Vector2f(iconScale,iconScale));
    weapon4.setSize(sf::Vector2f(iconScale,iconScale));
    weapon5.setSize(sf::Vector2f(iconScale,iconScale));
    weapon6.setSize(sf::Vector2f(iconScale,iconScale));
    weapon7.setSize(sf::Vector2f(iconScale,iconScale));
    weapon1.setPosition(295,790);
    weapon2.setPosition(423,790);
    weapon3.setPosition(551,790);
    weapon4.setPosition(679,790);
    weapon5.setPosition(807,790);
    weapon6.setPosition(935,790);
    weapon7.setPosition(1063,790);
    weapon1.setTexture(&lockIcon);
    weapon2.setTexture(&lockIcon);
    weapon3.setTexture(&lockIcon);
    weapon4.setTexture(&lockIcon);
    weapon5.setTexture(&lockIcon);
    weapon6.setTexture(&lockIcon);
    weapon7.setTexture(&lockIcon);

    survivorCnt.setFont(gameFont);
    survivorCnt.setCharacterSize(22);
    survivorCnt.setString("20/20 Survivors");
    survivorCnt.setFillColor(sf::Color(0,0,0,255));
    survivorCnt.setPosition(75,860);

//    grunt1 = new Grunt(lane1);
//    grunt2 = new Grunt(lane2);
//    grunt3 = new Grunt(lane3);
//    grunt4 = new Grunt(lane4);
//    grunt5 = new Grunt(lane5);

    for (unsigned int x=0; x<nEnemies; x++) {
    	Grunt *grunt = new Grunt(x+1);
		grunts.push_back(grunt);
    }

    gameMusic.setBuffer(gameSound);
    gameMusic.play();
    gameMusic.setLoop(true);


}

bool GameViewPlayer::playerViewIsOpen()
{
    sf::Clock clock;
    float delta;

    bool keepMovingUp = false;
    bool keepMovingDown = false;
    bool lockOutKeyboard = false;

    while(gameWindow.isOpen())
    {
        updateGame();


        delta = clock.getElapsedTime().asSeconds();
        clock.restart();

//        grunt1 -> moveGrunt(delta);
//        grunt2 -> moveGrunt(delta);
//        grunt3 -> moveGrunt(delta);
//        grunt4 -> moveGrunt(delta);
//        grunt5 -> moveGrunt(delta);

        for (unsigned int x=0; x<nEnemies; x++) {
        	grunts[x]->moveGrunt(delta);
        }

        if(keepMovingUp == true)
        {
            keepMovingUp = majorTom.keepMoving(delta, "Up");
            lockOutKeyboard = true;
        }
        else if(keepMovingDown == true)
        {
            keepMovingDown = majorTom.keepMoving(delta, "Down");
            lockOutKeyboard = true;
        }
        else
            lockOutKeyboard = false;

        //cout << "Move UP = " << keepMovingUp << " Move DOWN = " << keepMovingDown;
       //cout << " Major Tom Location = " << majorTom.getTomPosition() << endl;

         while(gameWindow.pollEvent(Event))
            {
                if(Event.type == sf::Event::Closed)
                {
                    gameWindow.close(); // Quit game
                    return true;
                }

                if(Event.type == sf::Event::KeyPressed)
                {
                    if(Event.key.code == sf::Keyboard::Escape)
                    {
                        gameWindow.close();
                        return true;
                    }

                    if(Event.key.code == sf::Keyboard::Up)
                    {
                        //majorTom.moveTomUp(delta);
                        if(lockOutKeyboard == false)
                        keepMovingUp = majorTom.initMove(delta, "Up");
                    }

                    if(Event.key.code == sf::Keyboard::Down)
                    {
                        //majorTom.moveTomDown(delta);
                        if(lockOutKeyboard == false)
                        keepMovingDown = majorTom.initMove(delta, "Down");
                    }

                    if(Event.key.code == sf::Keyboard::W)
                    {
                        //majorTom.moveTomUp(delta);
                        if(lockOutKeyboard == false)
                        keepMovingUp = majorTom.initMove(delta, "Up");
                    }

                    if(Event.key.code == sf::Keyboard::S)
                    {
                        //majorTom.moveTomDown(delta);
                        if(lockOutKeyboard == false)
                        keepMovingDown = majorTom.initMove(delta, "Down");
                    }
                }
            }
    }
    return false;
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

    gameWindow.draw(sky);
    gameWindow.draw(background);
    majorTom.drawTom(gameWindow);
//    grunt1 -> drawGrunt(gameWindow);
//    grunt2 -> drawGrunt(gameWindow);
//    grunt3 -> drawGrunt(gameWindow);
//    grunt4 -> drawGrunt(gameWindow);
//    grunt5 -> drawGrunt(gameWindow);
	for (unsigned int x=0; x<nEnemies; x++) {
		grunts[x]->drawGrunt(gameWindow);
	}
    gameWindow.draw(survivorCnt);
    gameWindow.draw(weapon1);
    gameWindow.draw(weapon2);
    gameWindow.draw(weapon3);
    gameWindow.draw(weapon4);
    gameWindow.draw(weapon5);
    gameWindow.draw(weapon6);
    gameWindow.draw(weapon7);

    gameWindow.display();
}

void GameViewPlayer::deleteObjects(void)
{
    delete currentPlayer;
}
