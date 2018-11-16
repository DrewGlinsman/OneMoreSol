/*
GameLogic.cpp

*/
#include "GameLogic.h"
#include "KoratBullet.h"
#include <iostream>
#include <typeinfo>

using namespace std;

GameLogic::GameLogic()
{
    loadedTextures = new TextureLoader();
    loadedAudio = new AudioLoader();

    if(currentLevel == 10)
    {
        startBikeBoss(loadedTextures);
    }
    if(currentLevel == 20)
    {
        startTankBoss(loadedTextures);
    }

}

bool GameLogic::checkEnd(MajorTom *majorTom)
{
    if(majorTom -> getSurvivors() == 0 || majorTom -> getHealth() <= 0)
    {
        survivorCountSaved = majorTom->getSurvivors();
        return true;
    }
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
        {
            if (dyingKorat[i] -> getName() == "Bomber")
                cout << "You Killed a Bomber" << endl;
            dyingKorat.erase(dyingKorat.begin() + i);
            currentKoratCount--;
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
        if(reloadTime > currentGun -> getReloadSpeed() && reloadStarted == true)
        {
            currentGun -> resetShotsFired();
            reloadClock.restart();
            reloadStarted = false;
            return true;
        }
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
                    if (currentBullet[i][j] -> getHeight() > currentKorat[i][0] -> getPositionX()) //If the bullet's X position is greater than X position of front facing Korat...
                    {
                    	//the bullet is past the korat that its supposed to be colliding with -- this means the korat is past tom
                    	//move the bullet anyways, but set "enemybehindtom" to true
                        currentBullet[i][j] -> moveCurrentBullet(timePassed);
                        enemyBehindTom = true;
                    }
                    else if(currentBullet[i][j] -> getPositionX() < currentKorat[i][0] -> getPositionX()) //if the bullet is not past the korat it's supposed to collide with
                    {
                    	//move the bullet closer to the korat
                    	//enemybehindtom is false because the bullet is still enroute to the enemy korat in the lane
                        currentBullet[i][j] -> moveCurrentBullet(timePassed);
                        enemyBehindTom = false;
                    }
                    else
                    {
                    	//the bullet has reached the korat -- start doing things that happen due to collision
                        currentKorat[i][0] -> wasShot(currentBullet[i][j] -> getDamage());
                        currentBullet[i].erase(currentBullet[i].begin() + j);
                        enemyBehindTom = false;

                    }
                }
                else if (currentKorat[i].size() > 1 && enemyBehindTom == true) //if there's more than one Korat and the latest Korat is behind tom
                {
                	//then we know to not look at the latest Korat but the one behind that Korat, which is hopefully also not behind Tom
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
                else //check and see if the bullet is out of bounds
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
    //on level 10 first boss checks for intersection with the boss, instead of using old collision
    //plug in sfml collision with rects
    else if (currentLevel == 10)
    {
        for (int i = 0; i < currentBullet.size(); i++)
        {
            for (int j = 0; j < currentBullet[i].size(); j++)
            {
                for (int z = 0; z < currentBikeBoss.size(); z++)
                {
                    if(currentBullet[i][j] -> getBullet().getGlobalBounds().intersects(currentBikeBoss[z] -> getBoss().getGlobalBounds()))
                    {
                        if(currentBullet[i][j] -> getBullet().getPosition().x > currentBikeBoss[z] -> getBoss().getPosition().x - 50)
                        {
                            currentBikeBoss[z] -> wasShot(currentBullet[i][j] -> getDamage());
                            currentBullet[i].erase(currentBullet[i].begin() + j);
                        }
                        else
                        {
                            currentBullet[i][j] -> moveCurrentBullet(timePassed);
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
                        }
                    }
                }
                if(currentBikeBoss.size() == 0)
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
        for (int i = 0; i < currentBullet.size(); i++)
        {
            for (int j = 0; j < currentBullet[i].size(); j++)
            {
                for (int z = 0; z < currentTankBoss.size(); z++)
                {
                    if(currentBullet[i][j] -> getBullet().getGlobalBounds().intersects(currentTankBoss[z] -> getBoss().getGlobalBounds()))
                    {
                        if(currentBullet[i][j] -> getBullet().getPosition().x > (currentTankBoss[z] -> getBoss().getPosition().x))
                        {
                        currentTankBoss[z] -> wasShot(currentBullet[i][j] -> getDamage());
                        currentBullet[i].erase(currentBullet[i].begin() + j);
                        }
                        else
                        {
                            currentBullet[i][j] -> moveCurrentBullet(timePassed);
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
                        }
                    }
                }
                if(currentTankBoss.size() == 0)
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

void GameLogic::moveKoratBullet(float timePassed, MajorTom* majorTom)
{
	//! KORAT BULLETS
	for (int i = 0; i < currentKoratBullet.size(); i ++)
	{
		for (int j = 0; j < currentKoratBullet[i].size(); j++)
		{
			if (currentKoratBullet[i][j] -> getBullet().getGlobalBounds().intersects(majorTom -> getTom().getGlobalBounds()))
			{
			    if(currentKoratBullet[i][j] -> getBullet().getPosition().x < majorTom -> getTomPositionX())
                {
                    majorTom -> wasShot(currentKoratBullet[i][j] -> getDamage());
                    currentKoratBullet[i].erase(currentKoratBullet[i].begin() + j);
                }
                else
                {
                    currentKoratBullet[i][j] -> moveCurrentBullet(timePassed);
                }
			}
			else
            {
				if (currentKoratBullet[i][j] -> getOutOfBounds() == false)
				{
					currentKoratBullet[i][j] -> moveCurrentBullet(timePassed);
				}
				else
				{
					currentKoratBullet[i].erase(currentKoratBullet[i].begin() + j);
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

    for (int i = 0; i < currentKoratBullet.size(); i ++)
	{
		for (int j = 0; j < currentKoratBullet[i].size(); j++)
		{
				currentKoratBullet[i][j] -> drawCurrentBullet(window);

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

int GameLogic::decideBulletLaneKorat(int givenLane)
{
    if (givenLane == lane1)
        return 1;
    else if (givenLane == lane2)
        return 2;
    else if (givenLane == lane3)
        return 3;
    else if (givenLane == lane4)
        return 4;
    else if (givenLane == lane5)
        return 5;
    else
        cout << "bullet shit is broken 2" << endl;
}

int GameLogic::decideBulletType(Gun* currentGun)
{
    return currentGun -> getBulletType();
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
    if (checkEnd(majorTom))
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

            // start text adventure

            if(currentLevel == 10)
            {
                startBikeBoss(loadedTextures);
            }

            if(currentLevel == 20)
            {
                startTankBoss(loadedTextures);
            }

        }
	}
	else if(currentLevel == 10 | currentLevel == 20)
    {
        gameSky.rotate(timePassed * levelSpeedModifier);
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

void GameLogic::clearAssets()
{
     for (int i = 0; i < currentBullet.size(); i++)
        {
            currentBullet[i].clear();
            currentKorat[i].clear();
            currentKoratBullet[i].clear();
        }
}

void GameLogic::loseLevel(sf::CircleShape& gameSky, MajorTom* majorTom)
{
    clearAssets();

    majorTom -> setTomPositionX(156);

    majorTom -> setTomPositionY(508);

    currentKoratCount = 0;

    gameSky.rotate(-rotation); //rotate the sun back to the beginning

    std::cout << "Current Level = " << currentLevel << std::endl;

    if(currentLevel == 10)
    {
        startBikeBoss(loadedTextures);
    }

    if(currentLevel == 20)
    {
        startTankBoss(loadedTextures);
    }

    majorTom->setSurvivors(survivorCountSaved);
    majorTom->setHealth(100);

}

void GameLogic::startBikeBoss(TextureLoader* loadedTextures)
{
    BikeBoss* bikeBoss = new BikeBoss(loadedTextures);
    currentBikeBoss.emplace_back(bikeBoss);
    currentKoratCount = 1;
}

void GameLogic::drawBikeBoss(sf::RenderWindow& window)
{
    for(int i = 0; i < currentBikeBoss.size(); i++)
    {
        currentBikeBoss[i] -> drawBoss(window);
    }
    for(int j = 0; j < dyingBikeBoss.size(); j++)
    {
        dyingBikeBoss[j] -> drawBoss(window);
    }
}

void GameLogic::updateDyingBikeBoss()
{
    for (int i = 0; i < dyingBikeBoss.size(); i++)
    {
        if (dyingBikeBoss[i] -> checkDeath() == true)
        {
            dyingBikeBoss.erase(dyingBikeBoss.begin() + i);
            currentKoratCount--;

        }
    }
}

void GameLogic::moveBikeBoss(sf::CircleShape& gameSky, MajorTom* majorTom, float timePassed)
{
    for(int i = 0; i < currentBikeBoss.size(); i++)
    {
        if (currentBikeBoss[i] -> checkSurvive() == false)
        {
            if (currentBikeBoss[i] -> checkDeath() == false)
            {
                if (currentBikeBoss[i] -> getSpeed() == 0)
                {
                        dyingBikeBoss.emplace_back(move(currentBikeBoss[i]));
                        currentBikeBoss.erase(currentBikeBoss.begin() + i);
                        movingUp = false;
                        movingDown = false;
                        directMove = 1;
                }
                else if (movingUp == false && movingDown == false)
                {
                    if (directMove < 1998)
                    {
                        directMove = Random() * 2000;
                        currentBikeBoss[i] -> moveBoss(timePassed);
                    }
                    else if (directMove >= 1998 && directMove < 1999)
                    {
                        directMove = Random() * 2000;
                        currentBikeBoss[i] -> initBossUp();
                        movingUp = true;
                        movingDown = false;
                    }
                    else if (directMove >= 1999)
                    {
                        directMove = Random() * 2000;
                        currentBikeBoss[i] -> initBossDown();
                        movingUp = false;
                        movingDown = true;
                    }
                }
                else if(movingUp == true)
                {
                    if (currentBikeBoss[i] -> moveBossUp(timePassed) == true)
                    {
                        movingUp = false;
                        movingDown = false;
                    }
                    currentBikeBoss[i] -> moveBoss(timePassed);
                }
                else if(movingDown == true)
                {
                    if (currentBikeBoss[i] -> moveBossDown(timePassed) == true)
                    {
                        movingUp = false;
                        movingDown = false;
                    }
                    currentBikeBoss[i] -> moveBoss(timePassed);
                }
            }
            else
            {
                // nothing happens will never trigger
            }
        }
        else
        {
            currentBikeBoss.erase(currentBikeBoss.begin() + i);
            currentKoratCount--;
            loseLevel(gameSky, majorTom);
        }
    }
}


void GameLogic::startTankBoss(TextureLoader* loadedTextures)
{
    TankBoss* tankBoss = new TankBoss(loadedTextures);
    currentTankBoss.emplace_back(tankBoss);
    currentKoratCount = 1;
}

void GameLogic::drawTankBoss(sf::RenderWindow& window)
{
     for(int i = 0; i < currentTankBoss.size(); i++)
    {
        currentTankBoss[i] -> drawBoss(window);
    }
    for(int j = 0; j < dyingTankBoss.size(); j++)
    {
        dyingTankBoss[j] -> drawBoss(window);
    }
}

void GameLogic::updateDyingTankBoss()
{
    for (int i = 0; i < dyingTankBoss.size(); i++)
    {
        if (dyingTankBoss[i] -> checkDeath() == true)
        {
            dyingTankBoss.erase(dyingTankBoss.begin() + i);
            currentKoratCount--;

        }
    }
}

void GameLogic::moveTankBoss(sf::CircleShape& gameSky, MajorTom* majorTom, float timePassed)
{
    for(int i = 0; i < currentTankBoss.size(); i++)
    {
        if (currentTankBoss[i] -> checkSurvive() == false)
        {
            if (currentTankBoss[i] -> checkDeath() == false)
            {
                if (currentTankBoss[i] -> getSpeed() == 0)
                {
                        dyingTankBoss.emplace_back(move(currentTankBoss[i]));
                        currentTankBoss.erase(currentTankBoss.begin() + i);
                }
                else
                {
                    currentTankBoss[i] -> moveBoss(timePassed);
                }
            }
            else
            {
                // nothing happens will never trigger
            }
        }
        else
        {
            currentBikeBoss.erase(currentBikeBoss.begin() + i);
            currentKoratCount--;
            loseLevel(gameSky, majorTom);
        }
    }
}

int GameLogic::getLevel()
{
    return currentLevel;
}


void GameLogic::queryKoratFiring()
{
	for (int i = 0; i < currentKorat.size(); i ++)
	{
		for (int j = 0; j < currentKorat[i].size(); j++)
		{

			if (currentKorat[i][j] -> getName() == "Jackal") //this only works for Jackals right now
			{
				if (currentKorat[i][j] -> queryToFire() == true) //if the Korat is ready to Fire
				{
					//implement stuff to make Korat fire here
					Bullet* newBullet;
					newBullet = new KoratBullet(currentKorat[i][j] -> getLane(), currentKorat[i][j] -> getPositionX(), loadedTextures);

					int laneToGoIn = decideBulletLaneKorat(currentKorat[i][j] -> getLane());
					currentKoratBullet[laneToGoIn - 1].emplace_back(newBullet);
				} else {
					//pass? basically ask again later
				}
			}
		}
	}
}
