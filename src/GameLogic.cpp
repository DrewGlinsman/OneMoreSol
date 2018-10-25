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
            if (currentKorat[i][j] -> checkDeath() == false)
            {
                currentKorat[i][j] -> moveCurrentKorat(timePassed);
            }
            else
            {
                currentKorat[i].erase(currentKorat[i].begin() + j);
            }
        }
    }
}

void GameLogic::drawKorat(sf::RenderWindow& window)
{
    for (int i = 0; i < currentKorat.size(); i ++)
    {
        for (int j = 0; j < currentKorat[i].size(); j++)
        {
                currentKorat[i][j] -> drawCurrentKorat(window);

        }
    }
}

void GameLogic::selectKorat(float timePassed)
{
    spawnLane = decideLane(timePassed);

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
            break;
        case 2:
            newKorat = new Jackal(spawnLane);
            break;
        case 3:
            newKorat = new Elite(spawnLane);
            break;
        case 4:
            newKorat = new Hunter(spawnLane);
            break;
        case 5:
            newKorat = new Brute(spawnLane);
            break;
        case 6:
            newKorat = new Bomber(spawnLane);
            break;
        case 7:
            newKorat = new Biker(spawnLane);
            break;
        default:
            newKorat = new Grunt(spawnLane);
            cout << "Break Case Activated" << endl;
            break;

    }
    currentKorat[spawnLane - 1].emplace_back(newKorat);

    cout << "==============================" << endl;
    for (int i = 0; i < currentKorat.size(); i ++)
    {

        for (int j = 0; j < currentKorat[i].size(); j++)
        {

            cout << currentKorat[i][j] -> getLane() << ' ';
            if (currentKorat[i][j] -> getLane() == 680)
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

int GameLogic::decideLane(float timePassed)
{
    PutSeed(-5);
    double lane = Random() * 5;
    if (lane >= 0 && lane <= 1)
        lane = 1;
    else if (lane > 1 && lane <= 2)
        lane = 2;
    else if (lane > 2 && lane <= 3)
        lane = 3;
    else if (lane > 3 && lane <= 4)
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

void GameLogic::runLevel(sf::CircleShape& gameSky, float timePassed)
{
	float rotation = gameSky.getRotation();

	//Chris, should we spawn first wave of Korat here?

	//Yes we should Jack, but not the first wave, just start the spawning process, it will know what level it is spawn appropriately.

	if (rotation >= sunSetOrientation) // if the sun has set
	{
		gameSky.rotate(-rotation); //rotate the sun back to the beginning
		currentLevel += 1;
		levelSpeedModifier = levelSpeedModifier * 15/16; //cut the speed of the sun down by 15/16ths

		//Chris, should we stop spawning Korat here, give a cool down time, then spawn them again?

		//No from here we stop spawning the Korat, once all Korat are dead we transition to the Text adventure,
		//afterwards we restart the process with the next level, with special checks for level 10 and 20 that
		//disable the spawning process and only spawn the bosses.
	}
	gameSky.rotate(timePassed * levelSpeedModifier);
}
