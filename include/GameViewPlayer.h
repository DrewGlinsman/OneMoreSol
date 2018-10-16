#ifndef GAMEVIEWPLAYER_H
#define GAMEVIEWPLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Gun.h"
#include "MajorTom.h"

using namespace std;

class GameViewPlayer
{

private:
    float timePassed;

public:
    sf::Font gameFont;
    const int iconScale = 75;

    sf::RenderWindow gameWindow;
    sf::RectangleShape background;
    sf::CircleShape sky;

    sf::RectangleShape weapon1;
    sf::RectangleShape weapon2;
    sf::RectangleShape weapon3;
    sf::RectangleShape weapon4;
    sf::RectangleShape weapon5;
    sf::RectangleShape weapon6;
    sf::RectangleShape weapon7;

    sf::Texture gameImage;
    sf::Texture playerImage;
    sf::Texture gameSky;
    sf::Texture lockIcon;

    sf::SoundBuffer gameSound;
    sf::Sound gameMusic;
    sf::Text survivorCnt;
    sf::Event Event;
    float* currentPlayer;
    MajorTom majorTom;

    GameViewPlayer();
    bool playerViewIsOpen();
    void movePlayer(float timePassed);
    void moveEnemy(float timePassed);
    void updateGame(void);
    void deleteObjects(void);


};

#endif
