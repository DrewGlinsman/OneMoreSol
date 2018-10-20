/*
GameLogic.cpp

*/
#include "GameLogic.h"
#include <iostream>

using namespace std;

GameLogic::GameLogic()
{
    survivorCount = 20;
}

bool GameLogic::checkEnd()
{
    if(survivorCount == 0)
        return true;
    return false;
}

void GameLogic::moveKorat(float timePassed)
{

}

void GameLogic::selectKorat(float timePassed)
{
    spawnLane = decideLane();

    if(currentLevel < 3)
        spawnType = decideType(enemyPool1);
    else if(currentLevel >= 3 && currentLevel < 6)
        spawnType = decideType(enemyPool2);
    else if(currentLevel >= 6 && currentLevel < 9)
        spawnType = decideType(enemyPool3);
    else if(currentLevel == 9)
        spawnType = decideType(enemyPool4);
    else if(currentLevel == 11)
        spawnType = decideType(enemyPool5);
    else if(currentLevel >= 12 && currentLevel < 15)
        spawnType = decideType(enemyPool6);
    else if(currentLevel >= 15 && currentLevel < 20)
        spawnType = decideType(enemyPool7);
    //cout << "Type = " << spawnType << " | Lane = " << spawnLane << endl;
    spawnKorat(timePassed);
}

void GameLogic::spawnKorat(float timePassed)
{
    KoratEmpire newKorat;
    newKorat.setLane(spawnLane);
    /*
    switch(spawnType)
    {
        case 1:
            (Grunt) newKorat = new Grunt(spawnLane);
        case 2:
            (Korat2) newKorat = new Korat2(spawnLane);
        case 3:
            (Korat3) newKorat = new Korat3(spawnLane);
    }
    */
}

int GameLogic::decideLane()
{
    double lane = Random() * 5;
    if (lane > 0 && lane < 1)
        lane = 1;
    else if (lane > 1 && lane < 2)
        lane = 2;
    else if (lane > 2 && lane < 3)
        lane = 3;
    else if (lane > 3 && lane < 4)
        lane = 4;
    else
        lane = 5;

    lane = (int) lane;
    return lane;
}

int GameLogic::decideType(std::vector<int> enemyPool)
{
    double enemyType = Random() * enemyPool.size();
    enemyType = (int) enemyType;
    return enemyPool[enemyType];
}
