
#ifndef GAMEVIEWPLAYER_H
#define GAMEVIEWPLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <typeinfo>
#include "Gun.h"
#include "MajorTom.h"
#include "GameLogic.h"
#include "TextureLoader.h"
#include "AudioLoader.h"

using namespace std;

class GameViewPlayer
{

private:
    bool initialized;

    sf::Clock delayClock;
    float delayClockTime;
    bool delayClockStarted;

    float timePassed;
    int savedGun;

    sf::Font menuFont;
    sf::Texture menuImage;
    sf::Texture playBtnImg;
    sf::Texture playBtnHImg;
    sf::Texture storyBtnImg;
    sf::Texture storyBtnHImg;
    sf::Texture exitBtnImg;
    sf::Texture exitBtnHImg;

    sf::RectangleShape menuBackground;
    sf::RectangleShape menuSelector;
    sf::RectangleShape playBtnRec;
    sf::RectangleShape storyBtnRec;
    sf::RectangleShape exitBtnRec;
    sf::RectangleShape nightSky;
    sf::RectangleShape winScreen;
    sf::RectangleShape controlScreen;

    sf::SoundBuffer Menu_Transition;
    sf::SoundBuffer Menu_Selection;
    sf::SoundBuffer Player_Firing_Weapon_Sound;
    sf::SoundBuffer Korat_Dying_Sound;
    sf::SoundBuffer Korat_Firing_Sound;
    sf::SoundBuffer Korat_Hit_Sound;
    sf::SoundBuffer Korat_Survived;
    sf::SoundBuffer Bomber_Exploding_Sound;

    sf::Sound menuTransition;
    sf::Sound menuSelection;
    sf::Sound textMusic;
    sf::Sound playerWeaponSound;
    sf::Sound koratDyingSound;
    sf::Sound koratFiringSound;
    sf::Sound koratHitSound;
    sf::Sound koratSurvivedSound;
    sf::Sound bomberExplodingSound;

    sf::Text menuTitle;
    sf::Text menuPlay1;
    sf::Text menuPlay2;
    sf::Text menuPlay3;
    sf::Text menuPlay4;
    sf::Text menuPlay5;
    sf::Text textAdventure;
    sf::Text koratKilledCnt;

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

    int koratKilled = 0;
    int jackalBulletsFired = 0;
    int eliteBulletsFired = 0;
    int bruteBulletsFired = 0;
    int hunterBulletsFired = 0;
    int bikerBulletsFired = 0;
    int tankBossBulletsFired = 0;
    int topBikerBulletsFired = 0;
    int middleBikerBulletsFired = 0;
    int bottomBikerBulletsFired = 0;
    int bombersExploded = 0;
    int koratHitCount = 0;
    int koratSurvived = 0;

    bool paused = false;

public:
    bool returnToMenu;
    sf::Font gameFont;
    const int iconScale = 64;
    int currentLevel;

    sf::RectangleShape journal;
    sf::RectangleShape background;
    sf::RectangleShape lossScreen;
    sf::RectangleShape reload1;
    sf::RectangleShape reload2;
    sf::RectangleShape reload3;
    sf::RectangleShape reload4;
    sf::RectangleShape reload5;
    sf::RectangleShape reload6;
    sf::RectangleShape reload7;

    std::array<sf::RectangleShape, 7> reloadRect;//holds the reload visualizations

    sf::CircleShape sky;

    sf::Sprite weapon1;
    sf::Sprite weapon2;
    sf::Sprite weapon3;
    sf::Sprite weapon4;
    sf::Sprite weapon5;
    sf::Sprite weapon6;
    sf::Sprite weapon7;
    sf::Sprite selectionBox;

    sf::Vector2f selector;
    sf::RectangleShape retryBtnRec;
    sf::RectangleShape giveUpBtnRec;
    sf::RectangleShape menuBtnRec;
    sf::RectangleShape winBtnRec;

    sf::Texture gameImage;
    sf::Texture playerImage;
    sf::Texture lockIcon;

    int lane1 = 335;
    int lane2 = 422;
    int lane3 = 508;
    int lane4 = 594;
    int lane5 = 680;

    sf::SoundBuffer gameSound;
    sf::Sound gameMusic;
    sf::Text survivorCnt;
    sf::Text scoreCnt;
    sf::Text levelCnt;
    sf::Text finalScoreCnt;
    sf::Text majorTomHealth;
    sf::Text pausedMsg;

    sf::Event Event;

    bool lost;
    bool optionSelected;

    GameLogic* logic;

    MajorTom* majorTom;

    TextureLoader* loadedTextures;
    AudioLoader* loadedAudio;

    GameViewPlayer();

    void initializeMenuState();
    void initializePlayState();
    void cleanUpMenuState();
    bool menuViewIsOpen(sf::RenderWindow& window);
    bool gameViewIsOpen(sf::RenderWindow& window);
    bool lossViewIsOpen(sf::RenderWindow& window);
    bool winViewIsOpen(sf::RenderWindow& window);
    bool storyViewIsOpen(sf::RenderWindow& window);
    bool textAdventureIsOpen(sf::RenderWindow& window);
    void drawAdventure(sf::RenderWindow& window);
    void updateMenu(sf::RenderWindow& window);
    void updateWinScreen(sf::RenderWindow& window);
    void updateGame(sf::RenderWindow& window);
    void updateSurvivorCount();
    void updateMajorTomHealth();
    void updateScoreCount();
    void updateLevelCount();
    void updateLossScreen(sf::RenderWindow &window);
    void selectButton(sf::RenderWindow &window, int y);
    void selectMenuButton(sf::RenderWindow &window, int y);
    void selectWinButton(sf::RenderWindow &window, int x);
    void resetGameToMenu(sf::RenderWindow &window);

};

#endif
