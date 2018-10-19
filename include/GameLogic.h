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
        std::list<std::reference_wrapper<KoratEmpire>> currentKorat;
        sf::SoundBuffer gunSound;
        sf::Sound gunSoundEffect;

    public:
        GameLogic();
        moveKorat();
        spawnKorat();
        checkEnd(GameViewPlayer* currentGame);

};


#endif
