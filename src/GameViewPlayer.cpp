#include "GameViewPlayer.h"
#include <iostream>
#include <fstream>

using namespace std;

GameViewPlayer::GameViewPlayer() // Player window constructor
{
    if(!initialized)
    {
        cout << "initializing" << endl;
        initializeMenuState();
        initializePlayState();
        logic = new GameLogic();
        //loadedAudio = new AudioLoader();
        majorTom = new MajorTom(loadedTextures);
    }
    initialized = true;
}

void GameViewPlayer::initializeMenuState()
{

    loadedTextures = new TextureLoader();
    loadedAudio = new AudioLoader();

    menuMusic.setBuffer(loadedAudio -> soundTrack[20]);
    menuTransition.setBuffer(loadedAudio -> soundTrack[21]);
    menuSelection.setBuffer(loadedAudio -> soundTrack[22]);

    menuBackground.setSize(sf::Vector2f(1,1));

    menuBackground.setPosition(0,0);
    menuBackground.setSize(sf::Vector2f(1440,900));
    menuBackground.setTexture(&(loadedTextures -> textureArray[4]));

    playBtnRec.setOrigin((1308/2),0);
    playBtnRec.setPosition(1440,400);
    playBtnRec.setSize(sf::Vector2f((1308/2),(224/2)));
    playBtnRec.setTexture(&(loadedTextures -> textureArray[6]));

    storyBtnRec.setOrigin((1050/2),0);
    storyBtnRec.setPosition(1440,530);
    storyBtnRec.setSize(sf::Vector2f((1050/2),(117/2)));
    storyBtnRec.setTexture(&(loadedTextures -> textureArray[7]));

    exitBtnRec.setOrigin((444),0);
    exitBtnRec.setPosition(1440,605);
    exitBtnRec.setSize(sf::Vector2f(444,(117/2)));
    exitBtnRec.setTexture(&(loadedTextures -> textureArray[9]));
}

void GameViewPlayer::initializePlayState()
{
    if(!gameFont.loadFromFile("assets/impact.ttf"))
        std::cout << "Could not load requested font." << std::endl;

    if (!lockIcon.loadFromFile("assets/lockIcon.png"))
        std::cout << "Failed to Load Lock Icon." << std::endl;

    //Store the reload rectangles into the array
    reloadRect[0] = reload1;
    reloadRect[1] = reload2;
    reloadRect[2] = reload3;
    reloadRect[3] = reload4;
    reloadRect[4] = reload5;
    reloadRect[5] = reload6;
    reloadRect[6] = reload7;

    sky.setRadius(894);
    sky.setOrigin(894,894);
    sky.setPosition(720, 450);
    sky.setTexture(&(loadedTextures->textureArray[2]));

    nightSky.setPosition(0,0);
    nightSky.setSize(sf::Vector2f(1440,760));
    nightSky.setFillColor(sf::Color(255,255,255,0));
    nightSky.setTexture(&(loadedTextures->textureArray[16]));

    background.setOrigin(0,724);
    background.setPosition(0,900);
    background.setSize(sf::Vector2f(1440,724));
    background.setTexture(&(loadedTextures -> textureArray[1]));

    lossScreen.setOrigin(0,900);
    lossScreen.setPosition(0,900);
    lossScreen.setSize(sf::Vector2f(1440,900));
    lossScreen.setTexture(&(loadedTextures -> textureArray[11]));

    winScreen.setOrigin(0,900);
    winScreen.setPosition(0,900);
    winScreen.setSize(sf::Vector2f(1440,900));
    winScreen.setTexture(&loadedTextures -> textureArray[17]);

    menuBtnRec.setPosition(215,780);
    menuBtnRec.setSize(sf::Vector2f(366,79));
    menuBtnRec.setTexture(&loadedTextures->textureArray[18]);

    winBtnRec.setPosition(900,780);
    winBtnRec.setSize(sf::Vector2f(366,79));
    winBtnRec.setTexture(&loadedTextures->textureArray[20]);

    retryBtnRec.setPosition(200, 600);
    retryBtnRec.setSize(sf::Vector2f(366, 79));
    retryBtnRec.setTexture(&(loadedTextures->textureArray[13]));

    giveUpBtnRec.setPosition(900, 600);
    giveUpBtnRec.setSize(sf::Vector2f(366,79));
    giveUpBtnRec.setTexture(&(loadedTextures->textureArray[14]));

    //Weapon icon and reload rectangle inits
    weapon1.setTextureRect(sf::IntRect(256,0,32,32));
    weapon2.setTextureRect(sf::IntRect(256,32,32,32));
    weapon3.setTextureRect(sf::IntRect(288,0,32,32));
    weapon4.setTextureRect(sf::IntRect(288,32,32,32));
    weapon5.setTextureRect(sf::IntRect(320,0,32,32));
    weapon6.setTextureRect(sf::IntRect(320,32,32,32));
    weapon7.setTextureRect(sf::IntRect(352,0,32,32));
    weapon1.setPosition(295,790);
    reloadRect[0].setPosition(376,867);
    weapon2.setPosition(423,790);
    reloadRect[1].setPosition(503,867);
    weapon3.setPosition(551,790);
    reloadRect[2].setPosition(632,867);
    weapon4.setPosition(679,790);
    reloadRect[3].setPosition(760,867);
    weapon5.setPosition(807,790);
    reloadRect[4].setPosition(888,867);
    weapon6.setPosition(935,790);
    reloadRect[5].setPosition(1016,867);
    weapon7.setPosition(1063,790);
    reloadRect[6].setPosition(1143,867);
    weapon1.setTexture(loadedTextures->textureArray[0]);
    weapon2.setTexture(loadedTextures->textureArray[0]);
    weapon3.setTexture(loadedTextures->textureArray[0]);
    weapon4.setTexture(loadedTextures->textureArray[0]);
    weapon5.setTexture(loadedTextures->textureArray[0]);
    weapon6.setTexture(loadedTextures->textureArray[0]);
    weapon7.setTexture(loadedTextures->textureArray[0]);
    weapon1.setScale(sf::Vector2f(2.5f,2.5f));
    weapon2.setScale(sf::Vector2f(2.5f,2.5f));
    weapon3.setScale(sf::Vector2f(2.5f,2.5f));
    weapon4.setScale(sf::Vector2f(2.5f,2.5f));
    weapon5.setScale(sf::Vector2f(2.5f,2.5f));
    weapon6.setScale(sf::Vector2f(2.5f,2.5f));
    weapon7.setScale(sf::Vector2f(2.5f,2.5f));

    for(int i = 0; i<7; ++i)
    {
        reloadRect[i].setFillColor(sf::Color(255,255,255,51));
        reloadRect[i].setSize(sf::Vector2f(64,0));
        reloadRect[i].setScale(sf::Vector2f(1.25f,1.25f));
        reloadRect[i].setRotation(180.f);
    }

    //Box around the selected weapon
    selectionBox.setTexture(loadedTextures->textureArray[0]);
	selectionBox.setTextureRect(sf::IntRect(0,896,95,95));
	selectionBox.setPosition(285,780);//init the selection box onto the first weapon

    //Survivor Count Display
    survivorCnt.setFont(gameFont);
    survivorCnt.setCharacterSize(22);
    survivorCnt.setString("20/20 Survivors");//might be able to take this out after survivor count is looped in updater
    survivorCnt.setFillColor(sf::Color(0,0,0,255));
    survivorCnt.setPosition(75,860);

    //Score count display
    scoreCnt.setFont(gameFont);
    scoreCnt.setCharacterSize(22);
    scoreCnt.setString("0 Score");//might be able to take out due to updater code redundancy
    scoreCnt.setFillColor(sf::Color(0,0,0,255));
    scoreCnt.setPosition(1300,20);

    //Level count display
    levelCnt.setFont(gameFont);
    levelCnt.setCharacterSize(22);
    levelCnt.setString("Sol /20");//might be able to take out due to updater code redundancy
    levelCnt.setFillColor(sf::Color(0,0,0,255));
    levelCnt.setPosition(1300,40);

    //Major Tom Health Display
	majorTomHealth.setFont(gameFont);
	majorTomHealth.setCharacterSize(22);
	majorTomHealth.setString("100/100 Health");//might be able to take this out after survivor count is looped in updater
	majorTomHealth.setFillColor(sf::Color(0,0,0,255));
	majorTomHealth.setPosition(75,770);

}

bool GameViewPlayer::menuViewIsOpen(sf::RenderWindow& window)
{
    menuMusic.play();
    menuMusic.setLoop(true);
    menuSelector.setPosition(0,0);
    cout << "0,0" << endl;
    while(window.isOpen()) // Menu loop
	{
        updateMenu(window);
		while(window.pollEvent(Event))
		{
			if(Event.type == sf::Event::Closed)
			{
				window.close(); // Quit game
				return true;
			}

			if(Event.type == sf::Event::KeyPressed)
			{
				if(Event.key.code == sf::Keyboard::Up)
				{
					if(sf::Vector2f (0,0) == menuSelector.getPosition())
					{
						menuSelector.setPosition(0,2);
						selectMenuButton(window,2);
						menuTransition.play();
						cout << "0,2" << endl;
					}
					else if(sf::Vector2f (0,1) == menuSelector.getPosition())
					{
						menuSelector.setPosition(0,0);
						selectMenuButton(window,0);
						menuTransition.play();
						cout << "0,0" << endl;
					}
					else if(sf::Vector2f (0,2) == menuSelector.getPosition())
					{
						menuSelector.setPosition(0,1);
						selectMenuButton(window,1);
						menuTransition.play();
						cout << "0,1" << endl;
					}
				}

				if(Event.key.code == sf::Keyboard::Down)
				{
					if(sf::Vector2f (0,0) == menuSelector.getPosition())
					{
						menuSelector.setPosition(0,1);
						selectMenuButton(window,1);
						menuTransition.play();
						cout << "0,1" << endl;
					}
					else if(sf::Vector2f (0,1) == menuSelector.getPosition())
					{
						menuSelector.setPosition(0,2);
						selectMenuButton(window,2);
						menuTransition.play();
						cout << "0,2" << endl;
					}
					else if(sf::Vector2f (0,2) == menuSelector.getPosition())
					{
						menuSelector.setPosition(0,0);
						selectMenuButton(window,0);
						menuTransition.play();
						cout << "0,0" << endl;
					}
				}

				if(Event.key.code == sf::Keyboard::Space || Event.key.code == sf::Keyboard::Return)
				{
					if(sf::Vector2f (0,0) == menuSelector.getPosition())
					{
						menuSelection.play();
						//Sleep(900); //cant use this on linux, find an alternative
						sf::sleep(sf::milliseconds(900)); //the fix
						menuMusic.stop();
						return false;
					}
					if(sf::Vector2f (0,1) == menuSelector.getPosition())
					{
						menuSelection.play();
						//Sleep(900); //cant use this on linux, find an alternative
						sf::sleep(sf::milliseconds(900)); //the fix
						menuMusic.stop();
						return false;
					}
					if(sf::Vector2f (0,2) == menuSelector.getPosition())
					{
						menuSelection.play();
						//Sleep(900); //cant use this on linux, find an alternative
						sf::sleep(sf::milliseconds(900)); //the fix
						window.close();
						return true;
					}
				}
			}
		}
	}
	return false;
}

void GameViewPlayer::updateMenu(sf::RenderWindow& window) // Updates screen
{
    window.clear(sf::Color::Black);
    window.draw(menuBackground);
    window.draw(playBtnRec);
    window.draw(storyBtnRec);
    window.draw(exitBtnRec);

    // display
    window.display();
}

bool GameViewPlayer::gameViewIsOpen(sf::RenderWindow& window)
{
    currentLevel = logic -> getLevel() - 1;

    sf::Clock fireRate1;
    sf::Clock fireRate2;

    float fireGun = fireRate1.getElapsedTime().asSeconds();


    sf::Clock gameClock;
    float delta;

    bool keepMovingUp = false;
    bool keepMovingDown = false;
    bool lockOutKeyboard = false;

    while(window.isOpen())
    {
        if(logic -> isTankBossDead())
        {
            winViewIsOpen(window);
        }

        updateGame(window);
        delta = gameClock.getElapsedTime().asSeconds();
        gameClock.restart();

//-----------------------------------------------------------------

        if (logic -> checkEnd(majorTom))
        {
            logic -> clearAssets();
            break;
        }

        if (logic -> currentLevelEnd())
        {
            std::cout << "Entered text adventure" << endl;
            logic -> pauseGame();
            textAdventureIsOpen(window);
        }

        if(currentLevel < logic -> getLevel())
        {
            gameMusic.stop();
            gameMusic.setBuffer(loadedAudio->soundTrack[logic -> getLevel() - 1]);
            gameMusic.play();
            gameMusic.setLoop(true);
        }

        currentLevel = logic -> getLevel();

        logic -> pauseGame();

        logic -> runLevel(sky, majorTom, delta, nightSky);
        logic -> updateKoratOrder();
        logic -> updateBulletOrder(); //Bullets generation and drawing
        logic -> updateDyingKorat(majorTom);
        logic -> moveKorat(delta, majorTom);
        logic -> queryKoratFiring();


        if (logic -> getLevel() == 10)
        {
            logic -> moveBikeBoss(sky, majorTom, delta);
            logic -> queryBikeFiring();
            logic -> updateDyingBikeBoss();
        }
        if (logic -> getLevel() == 20)
        {
            logic -> moveTankBoss(sky, majorTom, delta);
            logic -> queryTankFiring();
            logic -> updateDyingTankBoss();
        }

        logic -> moveBullet(delta);
        logic -> moveKoratBullet(delta, majorTom);


//-----------------------------------------------------------------
        if(keepMovingUp == true)
        {
            keepMovingUp = majorTom->keepMoving(delta, "Up");
            lockOutKeyboard = true;
        }
        else if(keepMovingDown == true)
        {
            keepMovingDown = majorTom->keepMoving(delta, "Down");
            lockOutKeyboard = true;
        }
        else
            lockOutKeyboard = false;

        //cout << "Move UP = " << keepMovingUp << " Move DOWN = " << keepMovingDown;
       //cout << " Major Tom Location = " << majorTom.getTomPosition() << endl;

         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                if(lockOutKeyboard == false)
                {
                     switch(majorTom -> getGun())
                    {
                        case 1:
                            logic -> fireBullet(majorTom, majorTom -> pistol, delta);
                            break;
                        case 2:
                            if (logic -> getLevel() >= 3)
                                logic -> fireBullet(majorTom, majorTom -> shotgun, delta);
                            break;
                        case 3:
                            if (logic -> getLevel() >= 5)
                                logic -> fireBullet(majorTom, majorTom -> rifle, delta);
                            break;
                        case 4:
                            if (logic -> getLevel() >= 7)
                                logic -> fireBullet(majorTom, majorTom -> minigun, delta);
                            break;
                        case 5:
                            if (logic -> getLevel() >= 9)
                                logic -> fireBullet(majorTom, majorTom -> thrower, delta);
                            break;
                        case 6:
                            if (logic -> getLevel() >= 11)
                                logic -> fireBullet(majorTom, majorTom -> sniper, delta);
                            break;
                        case 7:
                            if (logic -> getLevel() >= 13)
                                logic -> fireBullet(majorTom, majorTom -> bigFunGun, delta);
                            break;
                        default:
                            logic -> fireBullet(majorTom, majorTom -> pistol, delta);
                            break;
                    }
                }
            }

         while(window.pollEvent(Event))
            {
                if(Event.type == sf::Event::Closed)
                {
                    gameMusic.stop();
                    window.close(); // Quit game
                    return true;
                }

                if(Event.type == sf::Event::KeyPressed)
                {
                    if(Event.key.code == sf::Keyboard::Escape)
                    {
                        gameMusic.stop();
                        window.close();
                        return true;
                    }

                    if(Event.key.code == sf::Keyboard::Up)
                    {
                        if(lockOutKeyboard == false)
                        keepMovingUp = majorTom->initMove(delta, "Up");
                    }

                    if(Event.key.code == sf::Keyboard::Down)
                    {
                        if(lockOutKeyboard == false)
                        keepMovingDown = majorTom->initMove(delta, "Down");
                    }

                    if(Event.key.code == sf::Keyboard::W)
                    {
                        if(lockOutKeyboard == false)
                        keepMovingUp = majorTom->initMove(delta, "Up");
                    }

                    if(Event.key.code == sf::Keyboard::S)
                    {
                        if(lockOutKeyboard == false)
                        keepMovingDown = majorTom->initMove(delta, "Down");
                    }

                    if(Event.key.code == sf::Keyboard::Num1)
                    {
                        if(lockOutKeyboard == false)
                        {
                            majorTom->setGun(1);
                            selectionBox.setPosition(285,780);
                        }
                        std::cout << "selected plasma pistol" << std::endl;
                    }

                    if(Event.key.code == sf::Keyboard::Num2)
                    {
                        if(lockOutKeyboard == false)
                        {
                            majorTom->setGun(2);
                            selectionBox.setPosition(413,780);
                        }
                        cout << "selected plasma shotgun" << endl;

                    }

                    if(Event.key.code == sf::Keyboard::Num3)
                    {
                        if(lockOutKeyboard == false)
                        {
                            majorTom->setGun(3);
                            selectionBox.setPosition(541,780);
                        }
                        cout << "selected laser rifle" << endl;
                    }

                    if(Event.key.code == sf::Keyboard::Num4)
                    {
                        if(lockOutKeyboard == false)
                        {
                            majorTom->setGun(4);
                            selectionBox.setPosition(669,780);
                        }
                        cout << "selected laser minigun" << endl;
                    }

                    if(Event.key.code == sf::Keyboard::Num5)
                    {
                        if(lockOutKeyboard == false)
                        {
                            majorTom->setGun(5);
                            selectionBox.setPosition(797,780);
                        }
                        cout << "selected arc thrower" << endl;
                    }

                    if(Event.key.code == sf::Keyboard::Num6)
                    {
                        if(lockOutKeyboard == false)
                        {
                            majorTom->setGun(6);
                            selectionBox.setPosition(925,780);
                        }
                        cout << "selected gauss rifle" << endl;
                    }

                    if(Event.key.code == sf::Keyboard::Num7)
                    {
                        if(lockOutKeyboard == false)
                        {
                            majorTom->setGun(7);
                            selectionBox.setPosition(1053,780);
                        }
                        cout << "selected BFG" << endl;
                    }
                }
            }
        }
    return false;
}

bool GameViewPlayer::textAdventureIsOpen(sf::RenderWindow& window)
{

    gameMusic.stop();
    gameMusic.setBuffer(loadedAudio->soundTrack[24]);
    gameMusic.play();
    gameMusic.setLoop(true);

    window.clear(sf::Color::Black);
    drawAdventure(window);

    while(window.isOpen())
    {
        if (delayClockStarted == false)
        {
            delayClock.restart();
        }
        delayClockStarted = true;
        delayClockTime = delayClock.getElapsedTime().asSeconds();

        while(window.pollEvent(Event))
        {
            if(Event.type == sf::Event::KeyPressed)
            {
                if(Event.key.code == sf::Keyboard::Space)
                {
                    if(delayClockTime > 2)
                    {
                        gameMusic.stop();
                        return false;
                    }
                }
            }
        }
    }
    return false;
}

void GameViewPlayer::drawAdventure(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);
    std::string adventure;
    std::string sol;
    sf::Text solNum;
    std::string line;
    std::ifstream currentAdventure;
    int offset = 0;
    std::string fileString;
    fileString = "assets/TextAdventures/Level" + std::to_string(logic->getLevel())+ ".txt";
    currentAdventure.open(fileString);

    solNum.setFont(gameFont);
    solNum.setCharacterSize(24);
    solNum.setFillColor(sf::Color::White);
    solNum.setPosition(0,0);
    sol = "Sol " + std::to_string(logic -> getLevel());
    if(currentLevel == 10)
        sol = "Sol 11";
    solNum.setString(sol);
    window.draw(solNum);

    textAdventure.setFont(gameFont);
    textAdventure.setCharacterSize(32);
    textAdventure.setFillColor(sf::Color::White);

    while(getline(currentAdventure,line))
    {
        adventure = line;
        textAdventure.setString(adventure);
        textAdventure.setPosition(100, 250 + offset);
        window.draw(textAdventure);
        offset += 50;
    }


    window.display();
}

bool GameViewPlayer::lossViewIsOpen(sf::RenderWindow& window)
{
    gameMusic.stop();
    gameMusic.setBuffer(loadedAudio -> soundTrack[23]);
    gameMusic.play();
    gameMusic.setLoop(true);

    bool retry = false;
    updateLossScreen(window);
    while(window.isOpen() && !retry)
    {

        if (delayClockStarted == false)
        {
            delayClock.restart();
        }
        delayClockStarted = true;
        delayClockTime = delayClock.getElapsedTime().asSeconds();
        while(window.pollEvent(Event))
        {
            if(Event.type == sf::Event::Closed)
            {
                gameMusic.stop();
                window.close(); // Quit game
                return true;
            }

            if(Event.type == sf::Event::KeyPressed)
            {
                if(Event.key.code == sf::Keyboard::Escape)
                {
                    gameMusic.stop();
                    window.close();
                }

                if(Event.key.code == sf::Keyboard::Left || Event.key.code == sf::Keyboard::Right)
                {
                    if (selector.y == 1)
                    {
                        selector.y = 0;
                        selectButton(window, selector.y);
                    }
                    else
                    {
                        selector.y = 1;
                        selectButton(window, selector.y);
                    }
                }

                if(Event.key.code == sf::Keyboard::Space || Event.key.code == sf::Keyboard::Return)
                {
                    if(delayClockTime > 2)
                    {
                        if (selector.y == 0)
                        {
                            retry = true;
                            logic -> loseLevel(sky, majorTom);
                            return false;
                        }
                        else if (selector.y == 1)
                        {
                            gameMusic.stop();
                            window.close();
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

bool GameViewPlayer::winViewIsOpen(sf::RenderWindow& window)
{
    window.clear(sf::Color::Black);
    scoreCnt.setPosition(sf::Vector2f(600,700));
    scoreCnt.setFillColor(sf::Color::White);
    scoreCnt.setCharacterSize(44);
    string finalScore = "Final Score: " + std::to_string(majorTom -> getScore());
    scoreCnt.setString(finalScore);
    window.draw(winScreen);
    window.draw(winBtnRec);
    window.draw(menuBtnRec);
    window.draw(scoreCnt);
    window.display();
    while(window.isOpen())
    {
         while(window.pollEvent(Event))
         {
                if(Event.key.code == sf::Keyboard::Space)
                {
                    return false;
                }
         }
    }
    return false;
}

void GameViewPlayer::updateGame(sf::RenderWindow& window) // Draws all elements of screen
{
    window.clear(sf::Color::Black);

    window.draw(sky);
    window.draw(background);
    majorTom -> drawTom(window);

    logic -> drawKorat(window);


    if (logic -> getLevel() == 10)
    {
        logic -> drawBikeBoss(window);
    }
    if (logic -> getLevel() == 20)
    {
        logic -> drawTankBoss(window);
    }

    window.draw(nightSky);
    window.draw(selectionBox);
    window.draw(scoreCnt);
    window.draw(levelCnt);

    logic -> drawBullet(window);


    window.draw(survivorCnt);
    window.draw(majorTomHealth);
    window.draw(weapon1);
    if (logic -> getLevel() >= 3)
    	window.draw(weapon2);
    if (logic -> getLevel() >= 5)
    	window.draw(weapon3);
    if (logic -> getLevel() >= 7)
    	window.draw(weapon4);
    if (logic -> getLevel() >= 9)
    	window.draw(weapon5);
    if (logic -> getLevel() >= 11)
    	window.draw(weapon6);
    if (logic -> getLevel() >= 13)
    	window.draw(weapon7);

    for(int i = 0; i < 7; ++i)
    {
        for(int c = 0; c < 7; ++c)
        {
            reloadRect[c].setSize(sf::Vector2f(64.f,0.f));
        }
        if(logic->reloadStarted)
            reloadRect[majorTom->currentGun - 1].setSize(sf::Vector2f(64.f,(64.f * ((logic->reloadClock.getElapsedTime().asSeconds())-1))*2));
        if((64.f * ((logic->reloadClock.getElapsedTime().asSeconds())-1) > 32.f) || (64.f * ((logic->reloadClock.getElapsedTime().asSeconds())-1) < 0.f))
            reloadRect[majorTom->currentGun - 1].setSize(sf::Vector2f(64.f,0.f));

        window.draw(reloadRect[i]);
    }

    updateSurvivorCount();
    updateMajorTomHealth();
    updateScoreCount();
    updateLevelCount();

    window.display();
}

void GameViewPlayer::updateLossScreen(sf::RenderWindow &window)
{
        window.clear(sf::Color::Black);
        window.draw(lossScreen);
        window.draw(retryBtnRec);
        window.draw(giveUpBtnRec);
        window.display();
}

void GameViewPlayer::selectMenuButton(sf::RenderWindow& window, int y)
{
    if(y == 0)
    {
        playBtnRec.setTexture(&(loadedTextures -> textureArray[6]));
        storyBtnRec.setTexture(&(loadedTextures -> textureArray[7]));
        exitBtnRec.setTexture(&(loadedTextures -> textureArray[9]));
    }
    else if(y == 1)
    {
        playBtnRec.setTexture(&(loadedTextures -> textureArray[5]));
        storyBtnRec.setTexture(&(loadedTextures -> textureArray[8]));
        exitBtnRec.setTexture(&(loadedTextures -> textureArray[9]));
    }
    else if(y == 2)
    {
        playBtnRec.setTexture(&(loadedTextures -> textureArray[5]));
        storyBtnRec.setTexture(&(loadedTextures -> textureArray[7]));
        exitBtnRec.setTexture(&(loadedTextures -> textureArray[10]));
    }
    updateMenu(window);//could this be more optimally placed?
}

void GameViewPlayer::selectButton(sf::RenderWindow& window, int y)
{
    if(y == 0)
    {
        retryBtnRec.setTexture(&(loadedTextures->textureArray[13]));
        giveUpBtnRec.setTexture(&(loadedTextures->textureArray[14]));
    }
    else if(y == 1)
    {
        retryBtnRec.setTexture(&(loadedTextures->textureArray[12]));
        giveUpBtnRec.setTexture(&(loadedTextures->textureArray[15]));
    }
    updateLossScreen(window);
}


void GameViewPlayer::updateSurvivorCount()
{
    string cnt = std::to_string(majorTom->getSurvivors()) + "/20 Survivors";
    survivorCnt.setString(cnt);
}

void GameViewPlayer::updateMajorTomHealth()
{
	string cnt = std::to_string(majorTom->getHealth()) + "/100 Health";
	majorTomHealth.setString(cnt);
}

void GameViewPlayer::updateScoreCount()
{
    string cnt = std::to_string(majorTom->getScore()) + " Score";
    scoreCnt.setString(cnt);
}

void GameViewPlayer::updateLevelCount()
{
    string cnt = "Sol " + std::to_string(logic -> getLevel()) + "/20";
    levelCnt.setString(cnt);
}
