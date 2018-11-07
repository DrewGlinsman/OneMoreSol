/*
GameLogic.cpp

*/
#include "GameLogic.h"
#include <iostream>
#include <typeinfo>

using namespace std;

GameLogic::GameLogic()
{
    loadedTextures = new TextureLoader();


    if (!level1Music.loadFromFile("assets/Level_1_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 1 Music." << std::endl;

    if (!level2Music.loadFromFile("assets/Level_2_Cut.ogg")) // Loads and initializes all sounds based on impact
    std::cout << "Could not load Level 2 Music." << std::endl;

    backgroundMusic.setBuffer(level1Music);
    backgroundMusic.setVolume(50);
    backgroundMusic.play();

}

bool GameLogic::checkEnd()
{
    if(survivorCount == 0)
        return true;
    return false;
}

void GameLogic::updateKoratOrder()
{
    for (int i = 0; i < currentKorat.size(); i ++)
        {
            for (int j = 0; j < currentKorat[i].size(); j++)
            {
                if (j + 1 < currentKorat[i].size())
                {
                    if(currentKorat[i][j] -> getPositionX() > currentKorat[i][j+1] -> getPositionX())
                    {
                        currentKorat[i][j].swap(currentKorat[i][j+1]);
                    }
                }
            }
        }
}

void GameLogic::moveKorat(float timePassed, MajorTom* majorTom)
{
    for (int i = 0; i < currentKorat.size(); i ++)
    {
        for (int j = 0; j < currentKorat[i].size(); j++)
        {
            if (currentKorat[i][j] -> checkSurvive() == false)
            {
                if (currentKorat[i][j] -> checkDeath() == false)
                {
                    if (currentKorat[i][j] -> getSpeed() == 0)
                    {
                        dyingKorat.emplace_back(move(currentKorat[i][j]));
                        currentKorat[i].erase(currentKorat[i].begin() + j);
                        currentKoratCount--;
                    }
                    else
                    {
                    currentKorat[i][j] -> moveCurrentKorat(timePassed);
                    }
                }
                else
                {
                    // This will never be true!
                }
            }
            else
            {
                currentKorat[i].erase(currentKorat[i].begin() + j);
                currentKoratCount--;
                //update the gameviewplayer to reflect decremented survivors
                majorTom->setSurvivors(majorTom->getSurvivors()-1);
                std::cout << "survivor count = " << majorTom->getSurvivors() << std::endl;
            }
        }
    }
}

void GameLogic::updateDyingKorat()
{
    for (int i = 0; i < dyingKorat.size(); i++)
    {
        if (dyingKorat[i] -> checkDeath() == true)
            dyingKorat.erase(dyingKorat.begin() + i);
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
    for (int i = 0; i < dyingKorat.size(); i++)
    {
        dyingKorat[i] -> drawCurrentKorat(window);
    }
}

void GameLogic::selectKorat()
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
    spawnKorat();
}

void GameLogic::spawnKorat()
{
    KoratEmpire* newKorat;
    bool print;

    switch(koratSpawnType)
    {
        case 1:
            newKorat = new Grunt(koratSpawnLane, loadedTextures);
            break;
        case 2:
            newKorat = new Jackal(koratSpawnLane, loadedTextures);
            break;
        case 3:
            newKorat = new Elite(koratSpawnLane, loadedTextures);
            break;
        case 4:
            newKorat = new Hunter(koratSpawnLane, loadedTextures);
            break;
        case 5:
            newKorat = new Brute(koratSpawnLane, loadedTextures);
            break;
        case 6:
            newKorat = new Bomber(koratSpawnLane, loadedTextures);
            break;
        case 7:
            newKorat = new Biker(koratSpawnLane, loadedTextures);
            break;
        default:
            newKorat = new Grunt(koratSpawnLane, loadedTextures);
            std::cout << "Break Case Activated" << std::endl;
            break;

    }
    currentKorat[koratSpawnLane - 1].emplace_back(newKorat);
    currentKoratCount++;
    std::cout << "currentKoratCount = " << currentKoratCount << std::endl;

    std::cout << "==============================" << std::endl;
    for (int i = 0; i < currentKorat.size(); i ++)
    {

        for (int j = 0; j < currentKorat[i].size(); j++)
        {
            cout << currentKorat[i][j] -> getName() << ' ';
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

void GameLogic::updateBulletOrder()
{
    for (int i = 0; i < currentBullet.size(); i ++)
        {
            for (int j = 0; j < currentBullet[i].size(); j++)
            {
                if (j - 1 >= 0)
                {
                    if(currentBullet[i][j] -> getPositionX() < currentBullet[i][j-1] -> getPositionX())
                    {
                        currentBullet[i][j].swap(currentBullet[i][j-1]);
                    }
                }
            }
        }
}

void GameLogic::fireBullet(MajorTom* majorTom, Gun* currentGun, float timePassed)
{
    lastBulletFired = fireBulletClock.getElapsedTime().asSeconds();
    cout << lastBulletFired << endl;
    cout <<currentGun -> getFireRate() << endl;

    if((lastBulletFired > currentGun -> getFireRate()) &&
       (currentGun -> getShotsFired() != currentGun -> getClipSize()))
    {
           currentGun -> shotsFiredPlusOne();
           selectBullet(majorTom, currentGun, timePassed);
           fireBulletClock.restart();
    }
    else if(currentGun -> getShotsFired() == currentGun -> getClipSize())
    {
        if (reloadCurrentGun(majorTom, currentGun) == true)
        {
                currentGun -> shotsFiredPlusOne();
                selectBullet(majorTom, currentGun, timePassed);
                fireBulletClock.restart();
        }
    }

}

bool GameLogic::reloadCurrentGun(MajorTom* majorTom, Gun* currentGun)
{
    if(reloadStarted == false)
    {
        reloadClock.restart();
        reloadTime = reloadClock.getElapsedTime().asSeconds();
        reloadStarted = true;
    }
    if(reloadTime > currentGun -> getReloadSpeed() && reloadStarted == true)
    {
        currentGun -> resetShotsFired();
        reloadClock.restart();
        reloadStarted = false;
        return true;

    }
    else
    {
        reloadTime = reloadClock.getElapsedTime().asSeconds();
        cout << reloadTime << endl;
        return false;
    }
}

void GameLogic::moveBullet(float timePassed)
{
    if(currentLevel != 10 && currentLevel != 20)
    {
        for (int i = 0; i < currentBullet.size(); i ++)
        {
            for (int j = 0; j < currentBullet[i].size(); j++)
            {
                if (currentKorat[i].size() != 0 && enemyBehindTom == false)
                {
                    if (currentBullet[i][j] -> getHeight() > currentKorat[i][0] -> getPositionX())
                    {
                        currentBullet[i][j] -> moveCurrentBullet(timePassed);
                        enemyBehindTom = true;
                    }
                    else if(currentBullet[i][j] -> getPositionX() < currentKorat[i][0] -> getPositionX())
                    {
                        currentBullet[i][j] -> moveCurrentBullet(timePassed);
                        enemyBehindTom = false;
                    }
                    else
                    {
                        currentKorat[i][0] -> wasShot(currentBullet[i][j] -> getDamage());
                        currentBullet[i].erase(currentBullet[i].begin() + j);
                        enemyBehindTom = false;

                    }
                }
                else if (currentKorat[i].size() > 1 && enemyBehindTom == true)
                {
                     if (currentBullet[i][j] -> getHeight() > currentKorat[i][1] -> getPositionX())
                    {
                        currentBullet[i][j] -> moveCurrentBullet(timePassed);
                        enemyBehindTom = true;
                    }
                    else if(currentBullet[i][j] -> getPositionX() < currentKorat[i][1] -> getPositionX())
                    {
                        currentBullet[i][j] -> moveCurrentBullet(timePassed);
                        enemyBehindTom = false;
                    }
                    else
                    {
                        currentKorat[i][1] -> wasShot(currentBullet[i][j] -> getDamage());
                        currentBullet[i].erase(currentBullet[i].begin() + j);
                        enemyBehindTom = false;
                    }
                }
                else
                {
                    if (currentBullet[i][j] -> getOutOfBounds() == false)
                    {
                        currentBullet[i][j] -> moveCurrentBullet(timePassed);
                    }
                    else
                    {
                        currentBullet[i].erase(currentBullet[i].begin() + j);
                        enemyBehindTom = false;
                    }
                }
            }
        }
    }
    else if (currentLevel == 10)
    {
        for (int i = 0; i < currentBullet.size(); i ++)
        {
            for (int j = 0; j < currentBullet[i].size(); j++)
            {
                //if(currentBullet[i][j].getGlobalBounds().intersects(bikeBoss.getGlobalBounds()))
                {
                    //bikeBoss -> wasShot(currentBullet[i][j] -> getDamage());
                    currentBullet[i].erase(currentBullet[i].begin() + j);
                }
//                else
                {
                    if (currentBullet[i][j] -> getOutOfBounds() == false)
                    {
                        currentBullet[i][j] -> moveCurrentBullet(timePassed);
                    }
                    else
                    {
                        currentBullet[i].erase(currentBullet[i].begin() + j);
                    }
                }
            }
        }
    }
    else if (currentLevel == 20)
    {
        for (int i = 0; i < currentBullet.size(); i ++)
        {
            for (int j = 0; j < currentBullet[i].size(); j++)
            {
                //if(currentBullet[i][j].getGlobalBounds().intersects(tankBoss.getGlobalBounds()))
                {
                    //tankBoss -> wasShot(currentBullet[i][j] -> getDamage());
                    currentBullet[i].erase(currentBullet[i].begin() + j);
                }
//                else
                {
                    if (currentBullet[i][j] -> getOutOfBounds() == false)
                    {
                        currentBullet[i][j] -> moveCurrentBullet(timePassed);
                    }
                    else
                    {
                        currentBullet[i].erase(currentBullet[i].begin() + j);
                    }
                }
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

void GameLogic::selectBullet(MajorTom* majorTom, Gun* currentGun, float timePassed)
{
    bulletSpawnLane = decideBulletLane(majorTom);

    bulletSpawnType = decideBulletType(currentGun);

    spawnBullet(timePassed);
}

void GameLogic::spawnBullet(float timePassed)
{
    Bullet* newBullet;

    switch(bulletSpawnType)
    {
        case 1:
            newBullet = new PlasmaPistolBullet(bulletSpawnLane, loadedTextures);
            break;
        case 2:
            newBullet = new PlasmaShotgunBullet(bulletSpawnLane, loadedTextures);
            break;
        case 3:
            newBullet = new LaserRifleBullet(bulletSpawnLane, loadedTextures);
            break;
        case 4:
            newBullet = new LaserMinigunBullet(bulletSpawnLane, loadedTextures);
            break;
        case 5:
            newBullet = new ArcBullet(bulletSpawnLane, loadedTextures);
            break;
        case 6:
            newBullet = new GaussBullet (bulletSpawnLane, loadedTextures);
            break;
        case 7:
            newBullet = new BFGBullet (bulletSpawnLane, loadedTextures);
            break;
        default:
            newBullet = new PlasmaPistolBullet(bulletSpawnLane, loadedTextures);
            cout << "Break Case Activated" << endl;
            break;

    }
    currentBullet[bulletSpawnLane - 1].emplace_back(newBullet);
}

int GameLogic::decideBulletLane(MajorTom* majorTom)
{
    if (majorTom->getTomPosition() == lane1)
        return 1;
    else if (majorTom->getTomPosition() == lane2)
        return 2;
    else if (majorTom->getTomPosition() == lane3)
        return 3;
    else if (majorTom->getTomPosition() == lane4)
        return 4;
    else if (majorTom->getTomPosition() == lane5)
        return 5;
    else
        cout << "bullet shit is broken" << endl;
}

int GameLogic::decideBulletType(Gun* currentGun)
{
    if (currentGun -> getBulletType() == 1)
        return 1;
    else if (currentGun -> getBulletType() == 2)
        return 2;
    else if (currentGun -> getBulletType() == 3)
        return 3;
    else if (currentGun -> getBulletType() == 4)
        return 4;
    else if (currentGun -> getBulletType() == 5)
        return 5;
    else if (currentGun -> getBulletType() == 6)
        return 6;
    else if (currentGun -> getBulletType() == 7)
        return 7;

}


//----------------------------------------------------------

void GameLogic::runLevel(sf::CircleShape& gameSky, MajorTom* majorTom, float timePassed)
{
	rotation = gameSky.getRotation();
	spawnTime = spawnClock.getElapsedTime().asSeconds();

	long now;
    now = ((unsigned long) time((time_t *) NULL)) % 255;
    SelectStream((int) now);

    //-------------------------------------------------------------
    // lose game check
    if (majorTom->getSurvivors() == 0)
    {
        loseLevel(gameSky, majorTom);
    }

    //-------------------------------------------------------------

	if (rotation >= sunSetOrientation) // if the sun has set
	{
		if (currentKoratCount == 0)
        {
            gameSky.rotate(-rotation); //rotate the sun back to the beginning
            currentLevel++;
            survivorCountSaved = majorTom->getSurvivors();
            levelSpeedModifier = levelSpeedModifier * 15/16; //cut the speed of the sun down by 15/16ths
            levelSpawnModifier = levelSpawnModifier * 15/16; //

            majorTom ->  setTomPositionX(156);

            majorTom -> setTomPositionY(508);

            cout << "Current Level = " << currentLevel << endl;

            selectMusic();

            // start text adventure

            // transition to boss 1 if current level = 10

            // transition to boss 2 if current level = 20
        }
	}
	else
    {
        gameSky.rotate(timePassed * levelSpeedModifier);

        if (spawnTime >= levelSpawnModifier)
        {
            selectKorat();
            spawnClock.restart();
        }
    }
}

void GameLogic::selectMusic()
{
    switch(currentLevel)
    {
        case 2:
            backgroundMusic.setBuffer(level2Music);
            break;
        /*
        case 3:
            backgroundMusic.setBuffer(level3Music);
            break;
        case 4:
            backgroundMusic.setBuffer(level4Music);
            break;
        case 5:
            backgroundMusic.setBuffer(level5Music);
            break;
        case 6:
            backgroundMusic.setBuffer(level6Music);
            break;
        case 7:
            backgroundMusic.setBuffer(level7Music);
            break;
        case 8:
            backgroundMusic.setBuffer(level8Music);
            break;
        case 9:
            backgroundMusic.setBuffer(level9Music);
            break;
        case 10:
            backgroundMusic.setBuffer(level10Music);
            break;
        case 11:
            backgroundMusic.setBuffer(level11Music);
            break;
        case 12:
            backgroundMusic.setBuffer(level12Music);
            break;
        case 13:
            backgroundMusic.setBuffer(level13Music);
            break;
        case 14:
            backgroundMusic.setBuffer(level14Music);
            break;
        case 15:
            backgroundMusic.setBuffer(level15Music);
            break;
        case 16:
            backgroundMusic.setBuffer(level16Music);
            break;
        case 17:
            backgroundMusic.setBuffer(level17Music);
            break;
        case 18:
            backgroundMusic.setBuffer(level18Music);
            break;
        case 19:
            backgroundMusic.setBuffer(level19Music);
            break;
        case 20:
            backgroundMusic.setBuffer(level20Music);
            break;
        */
        default:
            std::cout << "Music selector broken" << std::endl;
    }
    backgroundMusic.setVolume(50);
    backgroundMusic.play();
}

void GameLogic::loseLevel(sf::CircleShape& gameSky, MajorTom* majorTom)
{

    for (int i = 0; i < 5; i++)
        {
            currentBullet[i].clear();
            currentKorat[i].clear();
        }

    majorTom -> setTomPositionX(156);

    majorTom -> setTomPositionY(508);

    currentKoratCount = 0;

    gameSky.rotate(-rotation); //rotate the sun back to the beginning

    std::cout << "Current Level = " << currentLevel << std::endl;

    selectMusic();

    majorTom->setSurvivors(survivorCountSaved);

}
