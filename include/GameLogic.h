
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <time.h>

#include "MajorTom.h"

#include "KoratEmpire.h"
#include "Grunt.h"
#include "Jackal.h"
#include "Elite.h"
#include "Hunter.h"
#include "Brute.h"
#include "Bomber.h"
#include "Biker.h"

#include "Bullet.h"
#include "ArcBullet.h"
#include "GaussBullet.h"
#include "LaserRifleBullet.h"
#include "LaserMinigunBullet.h"
#include "PlasmaPistolBullet.h"
#include "PlasmaShotgunBullet.h"
#include "BFGBullet.h"
#include "TextureLoader.h"

#include "rngs.h"

using namespace std;

class GameLogic{

    private:
        //wrap it in reference wrapper so that it passes references instead of copies
        std::vector<std::vector<shared_ptr<KoratEmpire>>> currentKorat {{},{},{},{},{}};
        std::vector<std::vector<shared_ptr<Bullet>>> currentBullet {{},{},{},{},{}};

        std::vector<shared_ptr<KoratEmpire>> dyingKorat{};

        sf::Clock spawnClock;
        sf::Clock fireBulletClock;
        sf::Clock reloadClock;

        int survivorCount = 20;
        int survivorCountSaved = 20;

        int currentKoratCount = 0;

        int currentLevel = 3;

        int koratSpawnLane;
        int koratSpawnType;

        int bulletSpawnLane;
        int bulletSpawnType;

        std::vector <int> enemyPool1 {1};
        std::vector <int> enemyPool2 {1, 2};
        std::vector <int> enemyPool3 {1, 2, 3};
        std::vector <int> enemyPool4 {1, 2, 3, 4};
        std::vector <int> enemyPool5 {1, 2, 3, 4, 5};
        std::vector <int> enemyPool6 {1, 2, 3, 4, 5, 6};
        std::vector <int> enemyPool7 {1, 2, 3, 4, 5, 6, 7};

        int lane1 = 335;
        int lane2 = 422;
        int lane3 = 508;
        int lane4 = 594;
        int lane5 = 680;

        int sunStartOrientation = 0;
        int sunRiseOrientation = 10;
        int sunSetOrientation = 150;
        float levelSpeedModifier = 2.5;
        float levelSpawnModifier = 1;
        float rotation;
        float spawnTime;
        bool enemyBehindTom = false;

        bool reloadStarted = false;
        float reloadTime;

        float lastBulletFired;

         sf::SoundBuffer level1Music;
         sf::SoundBuffer level2Music;
         sf::Sound backgroundMusic;

    public:
        GameLogic();

        TextureLoader* loadedTextures;

        //needs survivor count
        void moveKorat(float timePassed, MajorTom* majorTom);
        void drawKorat(sf::RenderWindow& window);

        void updateKoratOrder();
        void updateBulletOrder();

        void selectKorat();
        //needs survivor count
        void spawnKorat();
        bool checkEnd();

        int decideKoratLane();
        int decideKoratType(std::vector<int> enemyPool);

        void moveBullet(float timePassed);
        void drawBullet(sf::RenderWindow& window);

        void fireBullet(MajorTom* majorTom, float timePassed);
        bool reloadCurrentGun(MajorTom* majorTom);
        void selectBullet(MajorTom* majorTom, float timePassed);
        void spawnBullet(float timePassed);
        int decideBulletLane(MajorTom* majorTom);
        int decideBulletType(MajorTom* majorTom);

        //changes survivor count
        void runLevel(sf::CircleShape& gameSky, MajorTom* majorTom, float timePassed);

        void selectMusic();

        void loseLevel(sf::CircleShape& gameSky, MajorTom* majorTom);

        void updateDyingKorat();
};


#endif
