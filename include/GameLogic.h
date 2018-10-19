#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "GameViewPlayer.h"
#include "MajorTom.h"
#include "KoratEmpire.h"
#include "Grunt.h"
#include "Korat2.h"
#include "Korat3.h"
#include "rngs.h"

using namespace std;

class GameLogic{

    private:
        MajorTom majorTom;
        //wrap it in reference wrapper so that it passes references instead of copies
        std::vector<std::vector<KoratEmpire>> currentKorat;
        sf::SoundBuffer gunSound;
        sf::Sound gunSoundEffect;
        int survivorCount;
        int currentLevel = 19;

        double spawnRate;
        double spawnLane;
        double spawnType;

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

    public:
        GameLogic();
        void moveKorat(float timePassed);
        void selectKorat(float timePassed);
        void spawnKorat(float timePassed);
        bool checkEnd();
        int decideLane();
        int decideType(std::vector<int> enemyPool);

};


#endif
