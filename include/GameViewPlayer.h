#ifndef GAMEVIEWPLAYER_H
#define GAMEVIEWPLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Gun.h"

using namespace std;

class GameViewPlayer
{

private:
    float timePassed;

public:
    sf::Font gameFont;

    sf::RenderWindow gameWindow;
    sf::RectangleShape background;
    sf::Texture gameImage;
    sf::Texture playerImage;
    sf::SoundBuffer gameSound;
    sf::Sound gameMusic;

    float* currentPlayer;

    GameViewPlayer();
    void movePlayer(float timePassed);
    void moveEnemy(float timePassed);
    void updateGame(void);
    void deleteObjects(void);


};

#endif