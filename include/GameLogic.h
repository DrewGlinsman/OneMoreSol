
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

        int survivorCount = 20;
        int survivorCountSaved = 20;

        bool lostGame;
        bool tankBossDead = false;

        int currentKoratCount = 0;

        int currentLevel = 20;

        int koratSpawnLane;
        int koratSpawnType;

        int bulletSpawnLane;
        int bulletSpawnType;

        int counter = 0;

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
        std::vector <int> enemyPool5 {2, 3, 4, 5};
        std::vector <int> enemyPool6 {2, 3, 4, 5, 6};
        std::vector <int> enemyPool7 {3, 4, 5, 6, 7};

        std::vector <float> levelSpawnModifierVector {2.5, 2.4, 2.3, 2.2, 2.1, 2.0, 1.9, 1.8, 1.7, 1.6,
                                                      1.5, 1.4, 1.3, 1.2, 1.1, 1.0, .9, .8, .7, .6};

        std::vector <float> levelSpeedModifierVector {4.5, 4.5, 4.4, 4.4, 4.3, 4.3, 4.2, 4.2, 4.1, 2.1,
                                                      4.0, 4.0, 3.9, 3.9, 3.8, 3.8, 3.7, 3.7, 3.6, 3.6};

        const int lane1 = 335;
        const int lane2 = 422;
        const int lane3 = 508;
        const int lane4 = 594;
        const int lane5 = 680;

        int sunStartOrientation = 0;
        int sunRiseOrientation = 10;
        int sunSetOrientation = 150;
        float levelSpeedModifier = 4.5;
        float levelSpawnModifier = 2.5;
        float rotation;
        float spawnTime;
        bool enemyBehindTom = false;

        float reloadTime;

        float lastBulletFired;

        bool movingUp = false;
        bool movingDown = false;

        bool isPaused = false;

        double directMove = 1;

        int killedKorat = 0;
        int jackalBulletsFired = 0;
        int eliteBulletsFired = 0;
        int bruteBulletsFired = 0;
        int hunterBulletsFired = 0;
        int bikerBulletsFired = 0;
        int koratHitCount = 0;
        int koratSurvived = 0;
        int bombersExploded = 0;
        int tankBossBulletsFired = 0;

        //string howDidIDie;

    public:
        GameLogic();

        bool levelWon;

        sf::Clock reloadClock;
        bool reloadStarted = false;

        TextureLoader* loadedTextures;

        //needs survivor count
        void moveKorat(float timePassed, MajorTom* majorTom);
        void drawKorat(sf::RenderWindow& window);

        void updateKoratOrder();
        void updateBulletOrder();

        void selectKorat();
        //needs survivor count
        void spawnKorat();
        bool checkEnd(MajorTom*);
        int decideKoratLane();
        int decideKoratType(std::vector<int> enemyPool);

        void moveBullet(float);
        void moveKoratBullet(float, MajorTom*);
        void drawBullet(sf::RenderWindow&);

        bool fireBullet(MajorTom*, Gun*, float);
        bool reloadCurrentGun(Gun*);
        void selectBullet(MajorTom*, Gun*, float);
        void spawnBullet(float);
        int decideBulletLane(MajorTom*);
        int decideBulletLaneKorat(int);
        int decideBulletType(Gun*);

        void bulletLeftScreen(float timePassed, int i, int j);

        //changes survivor count
        void runLevel(sf::CircleShape&, MajorTom*, float, sf::RectangleShape&);

        void loseLevel(sf::CircleShape&, MajorTom*);

        void updateDyingKorat(MajorTom*);

        void startBikeBoss(TextureLoader*);
        void moveBikeBoss(sf::CircleShape&, MajorTom*, float);
        void drawBikeBoss(sf::RenderWindow&);
        void updateDyingBikeBoss();

        void startTankBoss(TextureLoader*);
        void moveTankBoss(sf::CircleShape&, MajorTom*, float);
        void drawTankBoss(sf::RenderWindow&);
        void updateDyingTankBoss();

        int getLevel();
        void setLevel(int lev);
        void queryKoratFiring();
        void queryBikeFiring();
        void queryTankFiring();

        void pauseGame();
        void explode(KoratEmpire &bomber, MajorTom* majorTom);
        void clearAssets();
        bool currentLevelEnd();

        bool isTankBossDead();

        int getKilledKorat();
        int getJackalBulletsFired();
        int getEliteBulletsFired();
        int getBruteBulletsFired();
        int getHunterBulletsFired();
        int getBikerBulletsFired();
        int getKoratHitCount();
        int getKoratSurvived();
        int getBombersExploded();
        int getTankBossBulletsFired();

        //string getHowDidIDie();

};


#endif
