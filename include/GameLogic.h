
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <time.h>

#include "MajorTom.h"
#include "BikeBoss.h"
#include "TankBoss.h"

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
#include "AudioLoader.h"
#include "rngs.h"

using namespace std;

class GameLogic{

    private:
        //wrap it in reference wrapper so that it passes references instead of copies
        std::vector<std::vector<shared_ptr<KoratEmpire>>> currentKorat {{},{},{},{},{}};
        std::vector<std::vector<shared_ptr<Bullet>>> currentBullet {{},{},{},{},{}};
        std::vector<std::vector<shared_ptr<Bullet>>> currentKoratBullet {{},{},{},{},{}};


        std::vector<shared_ptr<KoratEmpire>> dyingKorat{};

        std::vector<shared_ptr<BikeBoss>> currentBikeBoss{};
        std::vector<shared_ptr<BikeBoss>> dyingBikeBoss{};

        std::vector<shared_ptr<TankBoss>> currentTankBoss{};
        std::vector<shared_ptr<TankBoss>> dyingTankBoss{};

        sf::Clock spawnClock;
        sf::Clock fireBulletClock;
        sf::Clock reloadClock;

        int survivorCount = 20;
        int survivorCountSaved = 20;

        int currentKoratCount = 0;

        int currentLevel = 10;

        int koratSpawnLane;
        int koratSpawnType;

        int bulletSpawnLane;
        int bulletSpawnType;

        /*
            1 = Grunt
            2 = Jackal
            3 = Elite
            4 = Hunter
            5 = Brute
            6 = Bomber
            7 = MiniTank
        */

        std::vector <int> enemyPool1 {1};
        std::vector <int> enemyPool2 {1, 2};
        std::vector <int> enemyPool3 {1, 2, 3};
        std::vector <int> enemyPool4 {1, 2, 3, 4};
        std::vector <int> enemyPool5 {1, 2, 3, 4, 5};
        std::vector <int> enemyPool6 {1, 2, 3, 4, 5, 6};
        std::vector <int> enemyPool7 {1, 2, 3, 4, 5, 6, 7};

        const int lane1 = 335;
        const int lane2 = 422;
        const int lane3 = 508;
        const int lane4 = 594;
        const int lane5 = 680;

        int sunStartOrientation = 0;
        int sunRiseOrientation = 10;
        int sunSetOrientation = 150;
        float levelSpeedModifier = 10;
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

        bool lostGame;

        bool movingUp = false;
        bool movingDown = false;

        double directMove = 1;

    public:
        GameLogic();

        TextureLoader* loadedTextures;
        AudioLoader* loadedAudio;

        //needs survivor count
        void moveKorat(float timePassed, MajorTom* majorTom);
        void drawKorat(sf::RenderWindow& window);

        void updateKoratOrder();
        void updateBulletOrder();

        void selectKorat();
        //needs survivor count
        void spawnKorat();
        bool checkEnd(MajorTom *tom);
        int decideKoratLane();
        int decideKoratType(std::vector<int> enemyPool);

        void moveBullet(float timePassed);
        void moveKoratBullet(float timePassed, MajorTom* majorTom);
        void drawBullet(sf::RenderWindow& window);

        void fireBullet(MajorTom* majorTom, Gun* currentGun, float timePassed);
        bool reloadCurrentGun(MajorTom* majorTom, Gun* currentGun);
        void selectBullet(MajorTom* majorTom, Gun* currentGun, float timePassed);
        void spawnBullet(float timePassed);
        int decideBulletLane(MajorTom* majorTom);
        int decideBulletLaneKorat(int givenLane);
        int decideBulletType(Gun* currentGun);

        //changes survivor count
        void runLevel(sf::CircleShape& gameSky, MajorTom* majorTom, float timePassed);

        void loseLevel(sf::CircleShape& gameSky, MajorTom* majorTom);

        void updateDyingKorat();

        void startBikeBoss(TextureLoader*);
        void moveBikeBoss(sf::CircleShape& gameSky, MajorTom* majorTom, float timePassed);
        void drawBikeBoss(sf::RenderWindow& window);
        void updateDyingBikeBoss();

        void startTankBoss(TextureLoader*);
        void moveTankBoss(sf::CircleShape& gameSky, MajorTom* majorTom, float timePassed);
        void drawTankBoss(sf::RenderWindow& window);
        void updateDyingTankBoss();

        int getLevel();
        void queryKoratFiring();

        void clearAssets();

};


#endif
