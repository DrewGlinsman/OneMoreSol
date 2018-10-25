
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
#include "rngs.h"

using namespace std;

class GameLogic{

    private:
        //wrap it in reference wrapper so that it passes references instead of copies
        std::vector<std::vector<shared_ptr<KoratEmpire>>> currentKorat {{},{},{},{},{}};
        int survivorCount;
        int currentLevel = 19;

        double spawnRate;
        int spawnLane;
        int spawnType;

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

        int level = 1;
        int sunStartOrientation = 0;
        int sunRiseOrientation = 340;
        int sunSetOrientation = 134;
        float levelSpeedModifier = 20;

    public:
        GameLogic();
        void moveKorat(float timePassed);
        void drawKorat(sf::RenderWindow& window);

        void selectKorat(float timePassed);
        void spawnKorat(float timePassed);
        bool checkEnd();
        int decideLane();
        int decideType(std::vector<int> enemyPool);
        void runLevel(sf::CircleShape& gameSky, float timePassed);
};


#endif
