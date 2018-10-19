#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "GameViewPlayer.h"
#include "MajorTom.h"
#include "KoratEmpire.h"
#include "rngs.h"

using namespace std;

class GameLogic{

    private:
        MajorTom majorTom;
        //wrap it in reference wrapper so that it passes references instead of copies
        std::vector<KoratEmpire> currentKorat;
        sf::SoundBuffer gunSound;
        sf::Sound gunSoundEffect;
        int survivorCount;
        int lane1 = 335;
        int lane2 = 422;
        int lane3 = 508;
        int lane4 = 594;
        int lane5 = 680;

    public:
        GameLogic();
        moveKorat();
        spawnKorat();
        bool checkEnd();

};


#endif
