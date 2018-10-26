
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <SFML/Graphics.hpp>
#include <memory>

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
#include "LaserBullet.h"
#include "PlasmaBullet.h"
#include "TextureLoader.h"

#include "rngs.h"

using namespace std;

class GameLogic{

    private:
        //wrap it in reference wrapper so that it passes references instead of copies
        std::vector<std::vector<shared_ptr<KoratEmpire>>> currentKorat {{},{},{},{},{}};
        std::vector<std::vector<shared_ptr<Bullet>>> currentBullet {{},{},{},{},{}};
        int survivorCount;
        int currentLevel = 3;

        double spawnRate;
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

        int currentKoratCount = 0;

        int sunStartOrientation = 0;
        int sunRiseOrientation = 10;
        int sunSetOrientation = 134;
        float levelSpeedModifier = 20;

    public:
        GameLogic();

        TextureLoader* loadedTextures;

        void moveKorat(float timePassed);
        void drawKorat(sf::RenderWindow& window);

        void selectKorat(float timePassed);
        void spawnKorat(float timePassed);
        bool checkEnd();
        int decideKoratLane();
        int decideKoratType(std::vector<int> enemyPool);

        bool bulletHitsKorat(int checkLane,Bullet* selectedBullet, std::vector<std::vector<shared_ptr<KoratEmpire>>>* currentLaneKorat);

        void moveBullet(float timePassed);
        void drawBullet(sf::RenderWindow& window);

        void selectBullet(MajorTom majorTom, float timePassed);
        void spawnBullet(float timePassed);
        int decideBulletLane(MajorTom majorTom);
        int decideBulletType(MajorTom majorTom);



        void runLevel(sf::CircleShape& gameSky, float timePassed);
};


#endif
