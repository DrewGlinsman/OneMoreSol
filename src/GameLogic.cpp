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
                currentKoratCount--;
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
    koratSpawnLane = decideKoratLane();

    /*
        checks what level the player is on and
        decides what pool of types to randomly
        pick from excluding levels 10 and 20
        because they are boss levels
    */
    if(currentLevel < 3)
        koratSpawnType = decideKoratType(enemyPool1);
    else if(currentLevel >= 3 && currentLevel < 6)
        koratSpawnType = decideKoratType(enemyPool2);
    else if(currentLevel >= 6 && currentLevel < 9)
        koratSpawnType = decideKoratType(enemyPool3);
    else if(currentLevel == 9)
        koratSpawnType = decideKoratType(enemyPool4);
    else if(currentLevel == 11)
        koratSpawnType = decideKoratType(enemyPool5);
    else if(currentLevel >= 12 && currentLevel < 15)
        koratSpawnType = decideKoratType(enemyPool6);
    else if(currentLevel >= 15 && currentLevel < 20)
        koratSpawnType = decideKoratType(enemyPool7);
    //cout << "Type = " << koratSpawnType << " | Lane = " << koratSpawnLane << endl;
    spawnKorat(timePassed);
}

void GameLogic::spawnKorat(float timePassed)
{
    KoratEmpire* newKorat;
    bool print;

    switch(koratSpawnType)
    {
        case 1:
            newKorat = new Grunt(koratSpawnLane);
            break;
        case 2:
            newKorat = new Jackal(koratSpawnLane);
            break;
        case 3:
            newKorat = new Elite(koratSpawnLane);
            break;
        case 4:
            newKorat = new Hunter(koratSpawnLane);
            break;
        case 5:
            newKorat = new Brute(koratSpawnLane);
            break;
        case 6:
            newKorat = new Bomber(koratSpawnLane);
            break;
        case 7:
            newKorat = new Biker(koratSpawnLane);
            break;
        default:
            newKorat = new Grunt(koratSpawnLane);
            cout << "Break Case Activated" << endl;
            break;

    }
    currentKorat[koratSpawnLane - 1].emplace_back(newKorat);
    currentKoratCount++;
    cout << "currentKoratCount = " << currentKoratCount << endl;

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

int GameLogic::decideKoratLane()
{
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

int GameLogic::decideKoratType(std::vector<int> enemyPool)
{
    double enemyType = Random() * enemyPool.size();
    enemyType = (int) enemyType;
    return enemyPool[enemyType];
}

//----------------------------------------------------------
//Bullets generation and drawing

bool GameLogic::bulletHitsKorat(Bullet selectedBullet, std::vector<shared_ptr<KoratEmpire>> currentLaneKorat)
{
    for (int i = 0; i < currentLaneKorat.size(); i ++)
    {
//        if (selectedBullet.getBullet().getGlobalBounds().intersects(currentLaneKorat[i].getKorat().getGlobalBounds()) == true)
        {
            return true;
        }
    }
    return false;

}

void GameLogic::moveBullet(float timePassed)
{
    for (int i = 0; i < currentBullet.size(); i ++)
    {
        for (int j = 0; j < currentBullet[i].size(); j++)
        {
           // if (bulletHitsKorat(currentBullet[i][j], currentKorat[i]) == true)
            {
                currentBullet[i][j] -> moveCurrentBullet(timePassed);
            }
           // else
            {
           //     currentBullet[i].erase(currentBullet[i].begin() + j);
            }
        }
    }
}

void GameLogic::drawBullet(sf::RenderWindow& window)
{
    for (int i = 0; i < currentBullet.size(); i ++)
    {
        for (int j = 0; j < currentBullet[i].size(); j++)
        {
                currentBullet[i][j] -> drawCurrentBullet(window);

        }
    }
}

void GameLogic::selectBullet(MajorTom majorTom, float timePassed)
{
    bulletSpawnLane = decideBulletLane(majorTom);

    bulletSpawnType = decideBulletType(majorTom);

    spawnBullet(timePassed);
}

void GameLogic::spawnBullet(float timePassed)
{
    Bullet* newBullet;

    switch(bulletSpawnType)
    {
        case 1:
            newBullet = new PlasmaBullet(bulletSpawnLane);
            break;
        case 2:
//            newBullet = new LaserBullet(bulletSpawnLane);
            break;
        case 3:
 //           newBullet = new ArcBullet(bulletSpawnLane);
            break;
        case 4:
//            newBullet = new GaussBullet(bulletSpawnLane);
            break;
        //case 5:
            //newBullet = new BFGBullet(bulletSpawnLane);
        default:
            newBullet = new PlasmaBullet(koratSpawnLane);
            cout << "Break Case Activated" << endl;
            break;

    }
    currentBullet[bulletSpawnLane - 1].emplace_back(newBullet);
}

int GameLogic::decideBulletLane(MajorTom majorTom)
{
    if (majorTom.getTomPosition() == lane1)
        return 1;
    else if (majorTom.getTomPosition() == lane2)
        return 2;
    else if (majorTom.getTomPosition() == lane3)
        return 3;
    else if (majorTom.getTomPosition() == lane4)
        return 4;
    else if (majorTom.getTomPosition() == lane5)
        return 5;
    else
        cout << "bullet shit is broken" << endl;
}

int GameLogic::decideBulletType(MajorTom majorTom)
{
    if (majorTom.currentGun.bulletType = 1)
        return 1;
    else if (majorTom.currentGun.bulletType = 2)
        return 2;
    else if (majorTom.currentGun.bulletType = 3)
        return 3;
    else if (majorTom.currentGun.bulletType = 4)
        return 4;
    else if (majorTom.currentGun.bulletType = 5)
        return 5;
}


//----------------------------------------------------------

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
