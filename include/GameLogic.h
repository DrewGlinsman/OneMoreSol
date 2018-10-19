#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "GameViewPlayer.h"
#include "MajorTom.h"
#include "KoratEmpire.h"

using namespace std;

class GameLogic{

    private:
        MajorTom majorTom;
        //wrap it in reference wrapper so that it passes references instead of copies
        std::vector<KoratEmpire> currentKorat;
        sf::SoundBuffer gunSound;
        sf::Sound gunSoundEffect;
        int survivorCount;

    public:
        GameLogic();
        moveKorat();
        spawnKorat();
        bool checkEnd();

};


#endif
