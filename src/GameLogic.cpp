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

void GameLogic::spawnKorat(float timePassed)
{
    spawnLane = decideLane();
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
