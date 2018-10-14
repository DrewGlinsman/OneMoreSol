// Chris Wolinski SFML Pong

#ifndef GAMEVIEWMENU_H
#define GAMEVIEWMENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

using namespace std;

class GameViewMenu
{

private:
    sf::Font menuFont;
    sf::Texture menuImage;
    sf::Texture playBtnImg;
    sf::Texture playBtnHImg;
    sf::Texture storyBtnImg;
    sf::Texture storyBtnHImg;
    sf::Texture exitBtnImg;
    sf::Texture exitBtnHImg;

    sf::RectangleShape background;
    sf::RectangleShape playBtnRec;
    sf::RectangleShape storyBtnRec;
    sf::RectangleShape exitBtnRec;
    sf::SoundBuffer menuSound;
    sf::Sound menuMusic;
    sf::Text menuTitle;
    sf::Text menuPlay1;
    sf::Text menuPlay2;
    sf::Text menuPlay3;
    sf::Text menuPlay4;
    sf::Text menuPlay5;

    float titleX = 130;
    float titleY = 20;

    float playX1 = 40;
    float playY1 = 165;

    float playX2 = 30;
    float playY2 = 205;

    float playX3 = 30;
    float playY3 = 245;

    float playX4 = 168;
    float playY4 = 245;

    float playX5 = 262;
    float playY5 = 245;

public:
    sf::RenderWindow menuWindow;
    GameViewMenu();
    bool menuSelection();
    void updateMenu(void);
    void selectButton(int, int);


};

#endif
