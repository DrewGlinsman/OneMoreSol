/*
GameLogic.cpp

*/
#include "GameLogic.h"

GameLogic::GameLogic()
{
    survivorCount = 20;
}

bool GameLogic::checkEnd()
{
    if(survivorCount == 0)
        return true;
}

