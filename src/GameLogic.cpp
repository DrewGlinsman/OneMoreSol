/*
GameLogic.cpp

*/
#include "GameLogic.h"
#include <iostream>
#include <typeinfo>

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
    for (int i = 0; i < currentKorat.size(); i ++)
    {
        for (int j = 0; j < currentKorat[i].size(); j++)
        {
            currentKorat[i][j].moveCurrentKorat(timePassed);
        }
    }
}

void GameLogic::drawKorat(sf::RenderWindow& window)
{
    for (int i = 0; i < currentKorat.size(); i ++)
    {
        for (int j = 0; j < currentKorat[i].size(); j++)
        {
            currentKorat[i][j].drawCurrentKorat(window);
        }
    }
}

void GameLogic::selectKorat(float timePassed)
{
    spawnLane = decideLane();

    /*
        checks what level the player is on and
        decides what pool of types to randomly
        pick from excluding levels 10 and 20
        because they are boss levels
    */
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
    KoratEmpire* newKorat;
    bool print;

    switch(spawnType)
    {
        case 1:
            newKorat = new Grunt(spawnLane);
        /*
        case 2:
            newKorat = new Korat2(spawnLane);
        case 3:
            newKorat = new Korat3(spawnLane);
        case 4:
            newKorat = new Korat4(spawnLane);
        case 5:
            newKorat = new Korat5(spawnLane);
        case 6:
            newKorat = new Korat6(spawnLane);
        case 7:
            newKorat = new Korat7(spawnLane);
        */
        default:
            newKorat = new Grunt(spawnLane);
    }
    currentKorat[spawnLane - 1].push_back(*newKorat);

    cout << endl;
    cout << "==============================" << endl;
    for (int i = 0; i < currentKorat.size(); i ++)
    {

        for (int j = 0; j < currentKorat[i].size(); j++)
        {

            cout << currentKorat[i][j].getLane() << ' ';
            if (currentKorat[i][j].getLane() == 680)
            {
                 print = false;
            }
            else
                 print = true;

        }
        if(print == true)
        cout << endl << "------------------------------" << endl;
        else
            cout << endl;
    }
    cout << "==============================" << endl;
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
