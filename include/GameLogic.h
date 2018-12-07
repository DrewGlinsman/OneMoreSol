
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
        //separate vectors to hold the dying enemies to allow bullets to pass through them and hit living ones behind them
        std::vector<shared_ptr<Bullet>> dyingGauss {};
        std::vector<shared_ptr<KoratEmpire>> dyingKorat{};
        //vectors to hold the bosses for separate handling
        std::vector<shared_ptr<BikeBoss>> currentBikeBoss{};
        std::vector<shared_ptr<BikeBoss>> dyingBikeBoss{};

        std::vector<shared_ptr<TankBoss>> currentTankBoss{};
        std::vector<shared_ptr<TankBoss>> dyingTankBoss{};

        sf::Clock spawnClock;
        sf::Clock fireBulletClock;
        //init counts for checks and updates
        int survivorCount = 20;
        int survivorCountSaved = 20;

        bool lostGame = false;
        bool tankBossDead = false;


        int currentKoratCount = 0;
        //change the current level
        int currentLevel = 19;

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
        //holds the types of enemies allowed to spawn
        //enemy pools used are changed based on level checks
        std::vector <int> enemyPool1 {1};
        std::vector <int> enemyPool2 {1, 2};
        std::vector <int> enemyPool3 {1, 2, 3};
        std::vector <int> enemyPool4 {1, 2, 3, 4};
        std::vector <int> enemyPool5 {2, 3, 4, 5};
        std::vector <int> enemyPool6 {2, 3, 4, 5, 6};
        std::vector <int> enemyPool7 {3, 4, 5, 6, 7};

        std::vector <float> levelSpawnModifierVector {2.0, 1.9, 1.8, 1.7, 1.5, 1.4, 1.3, 1.2, 1.2, 1.1,
                                                      1.2, 1.2, 1.2, 1.2, 1.2, 1.1, 1.1, 1.1, 1.0, .1};

        std::vector <float> levelSpeedModifierVector {7.5, 7.4, 7.3, 7.2, 7.1, 7.0, 6.9, 6.8, 6.7, 6.6,
                                                      6.5, 6.4, 6.3, 6.2, 6.1, 6.0, 5.9, 5.8, 5.7, 4.5};
        //holds lane centers for entity reference
        const int lane1 = 335;
        const int lane2 = 422;
        const int lane3 = 508;
        const int lane4 = 594;
        const int lane5 = 680;

        int sunStartOrientation = 0;
        int sunRiseOrientation = 10;
        int sunSetOrientation = 150;
        float levelSpeedModifier = 7.5;
        float levelSpawnModifier = 2;
        float rotation;
        float spawnTime;
        bool enemyBehindTom = false;

        float lastBulletFired;
        //used to make sure tom doesn't get stuck between a lane
        bool movingUp = false;
        bool movingDown = false;

        bool isPaused = false;

        double directMove = 1;

        int topBikerBulletsFired = 0;
        int middleBikerBulletsFired = 0;
        int bottomBikerBulletsFired = 0;

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
        bool firstLevel = true;

        sf::Clock reloadClock;
        bool reloadStarted = false;
        bool reloadFinished = false;
        float reloadTime;

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
        void gaussLeftScreen(float timePassed);

        bool fireBullet(MajorTom*, Gun*, float);
        bool reloadCurrentGun(Gun*);
        void selectBullet(MajorTom*, Gun*, float);
        void spawnBullet(float);
        int decideBulletLane(MajorTom*);
        int decideBulletLaneKorat(int);
        int decideBulletType(Gun*);

        void bulletLeftScreen(float timePassed, int i, int j);

        //changes survivor count
        void runLevel(sf::CircleShape&, MajorTom*, float, sf::RectangleShape&, sf::RectangleShape&);

        void loseLevel(sf::CircleShape&, MajorTom*);

        void updateDyingKorat(MajorTom*);

        void startBikeBoss(TextureLoader*);
        void moveBikeBoss(sf::CircleShape&, MajorTom*, float);
        void drawBikeBoss(sf::RenderWindow&);
        void updateDyingBikeBoss(MajorTom*);

        void startTankBoss(TextureLoader*);
        void moveTankBoss(sf::CircleShape&, MajorTom*, float);
        void drawTankBoss(sf::RenderWindow&);
        void updateDyingTankBoss(MajorTom*);

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

        int getTopBikerBulletsFired();
        int getMiddleBikerBulletsFired();
        int getBottomBikerBulletsFired();

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

        bool getIsPaused();

        float getRotation();
        void setTankBossBool(bool b);
        //string getHowDidIDie();

};


#endif
