#include "GameViewPlayer.h"

using namespace std;

GameViewPlayer::GameViewPlayer() // Player window constructor
{
    if(!gameFont.loadFromFile("assets/impact.ttf"))
        std::cout << "Could not load requested font." << std::endl;

    if (!gameSound.loadFromFile("assets/Gamex_Music.ogg"))
        std::cout << "Could not load request music." << std::endl;

    if (!lockIcon.loadFromFile("assets/lockIcon.png"))
        std::cout << "Failed to Load Lock Icon." << std::endl;

    loadedTextures = new TextureLoader();

    sky.setRadius(894);
    sky.setOrigin(894,894);
    sky.setPosition(720, 450);
    sky.setTexture(&(loadedTextures->textureArray[2]));

    background.setOrigin(0,724);
    background.setPosition(0,900);
    background.setSize(sf::Vector2f(1440,724));
    background.setTexture(&(loadedTextures->textureArray[1]));

    lossScreen.setTexture(&(loadedTextures->textureArray[11]));

    weapon1.setTextureRect(sf::IntRect(256,0,32,32));
    weapon2.setTextureRect(sf::IntRect(256,32,32,32));
    weapon3.setTextureRect(sf::IntRect(288,0,32,32));
    weapon4.setTextureRect(sf::IntRect(288,32,32,32));
    weapon5.setTextureRect(sf::IntRect(320,0,32,32));
    weapon6.setTextureRect(sf::IntRect(320,32,32,32));
    weapon7.setTextureRect(sf::IntRect(352,0,32,32));
    weapon1.setPosition(295,790);
    weapon2.setPosition(423,790);
    weapon3.setPosition(551,790);
    weapon4.setPosition(679,790);
    weapon5.setPosition(807,790);
    weapon6.setPosition(935,790);
    weapon7.setPosition(1063,790);
    weapon1.setTexture(loadedTextures->mtSpriteSheet);
    weapon2.setTexture(loadedTextures->mtSpriteSheet);
    weapon3.setTexture(loadedTextures->mtSpriteSheet);
    weapon4.setTexture(loadedTextures->mtSpriteSheet);
    weapon5.setTexture(loadedTextures->mtSpriteSheet);
    weapon6.setTexture(loadedTextures->mtSpriteSheet);
    weapon7.setTexture(loadedTextures->mtSpriteSheet);
    weapon1.setScale(sf::Vector2f(2.5f,2.5f));
    weapon2.setScale(sf::Vector2f(2.5f,2.5f));
    weapon3.setScale(sf::Vector2f(2.5f,2.5f));
    weapon4.setScale(sf::Vector2f(2.5f,2.5f));
    weapon5.setScale(sf::Vector2f(2.5f,2.5f));
    weapon6.setScale(sf::Vector2f(2.5f,2.5f));
    weapon7.setScale(sf::Vector2f(2.5f,2.5f));

    //Survivor Count Display
    survivorCnt.setFont(gameFont);
    survivorCnt.setCharacterSize(22);
    survivorCnt.setString("20/20 Survivors");//might be able to take this out after survivor count is looped in updater
    survivorCnt.setFillColor(sf::Color(0,0,0,255));
    survivorCnt.setPosition(75,860);

    logic = new GameLogic();
    majorTom = new MajorTom(loadedTextures);

    gameMusic.setBuffer(gameSound);

}

bool GameViewPlayer::gameViewIsOpen(sf::RenderWindow& window)
{
    gameMusic.play();
    gameMusic.setLoop(true);

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
        updateGame(window);

        delta = gameClock.getElapsedTime().asSeconds();
        gameClock.restart();

//-----------------------------------------------------------------

        logic -> runLevel(sky, majorTom, delta);
        logic -> updateKoratOrder();
        logic -> updateBulletOrder();
        logic -> updateDyingKorat();
        logic -> moveKorat(delta, majorTom);

        if (logic -> getLevel() == 10)
        {
            logic -> moveBikeBoss(sky, majorTom, delta);
        }
        if (logic -> getLevel() == 20)
        {
            //logic -> moveTankBoss(delta);
        }

        logic -> moveBullet(delta);

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

                    if(Event.key.code == sf::Keyboard::Space)
                    {
                        if(lockOutKeyboard == false)
                        {

                             switch(majorTom -> getGun())
                            {
                                case 1:
                                    logic -> fireBullet(majorTom, majorTom -> pistol, delta);
                                    break;
                                case 2:
                                    logic -> fireBullet(majorTom, majorTom -> shotgun, delta);
                                    break;
                                case 3:
                                    logic -> fireBullet(majorTom, majorTom -> rifle, delta);
                                    break;
                                case 4:
                                    logic -> fireBullet(majorTom, majorTom -> minigun, delta);
                                    break;
                                case 5:
                                    logic -> fireBullet(majorTom, majorTom -> thrower, delta);
                                    break;
                                case 6:
                                    logic -> fireBullet(majorTom, majorTom -> sniper, delta);
                                    break;
                                case 7:
                                    logic -> fireBullet(majorTom, majorTom -> bigFunGun, delta);
                                    break;
                                default:
                                    logic -> fireBullet(majorTom, majorTom -> pistol, delta);
                                    break;
                            }

                        }
                    }

                    if(Event.key.code == sf::Keyboard::Num1)
                    {
                        if(lockOutKeyboard == false)
                        majorTom->setGun(1);
                        cout << "selected plasma pistol" << endl;
                    }

                    if(Event.key.code == sf::Keyboard::Num2)
                    {
                        if(lockOutKeyboard == false)
                        majorTom->setGun(2);
                        cout << "selected plasma shotgun" << endl;

                    }

                    if(Event.key.code == sf::Keyboard::Num3)
                    {
                        if(lockOutKeyboard == false)
                        majorTom->setGun(3);
                        cout << "selected laser rifle" << endl;
                    }

                    if(Event.key.code == sf::Keyboard::Num4)
                    {
                        if(lockOutKeyboard == false)
                        majorTom->setGun(4);
                        cout << "selected laser minigun" << endl;
                    }

                    if(Event.key.code == sf::Keyboard::Num5)
                    {
                        if(lockOutKeyboard == false)
                        majorTom->setGun(5);
                        cout << "selected arc thrower" << endl;
                    }

                    if(Event.key.code == sf::Keyboard::Num6)
                    {
                        if(lockOutKeyboard == false)
                        majorTom->setGun(6);
                        cout << "selected gauss rifle" << endl;
                    }

                    if(Event.key.code == sf::Keyboard::Num7)
                    {
                        if(lockOutKeyboard == false)
                        majorTom->setGun(7);
                        cout << "selected BFG" << endl;
                    }
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
    logic -> drawBullet(window);

    if (logic -> checkEnd())
    {
        drawLossScreen(window);
        //draw retry screen
    }

    if (logic -> getLevel() == 10)
    {
        logic -> drawBikeBoss(window);
    }
    if (logic -> getLevel() == 20)
    {
        logic -> drawTankBoss(window);
    }

    window.draw(survivorCnt);
    window.draw(weapon1);
    window.draw(weapon2);
    window.draw(weapon3);
    window.draw(weapon4);
    window.draw(weapon5);
    window.draw(weapon6);
    window.draw(weapon7);

    updateSurvivorCount();

    window.display();
}

void GameViewPlayer::drawLossScreen(sf::RenderWindow &window)
{
        //window.draw(lossScreen) #need a loss screen to implement
        bool retry = false;
        while(window.isOpen() && !retry)
        {
            while(window.pollEvent(Event))
            {
                if(Event.type == sf::Event::Closed)
                {
                    gameMusic.stop();
                    window.close(); // Quit game
                }

                if(Event.type == sf::Event::KeyPressed)
                {
                    if(Event.key.code == sf::Keyboard::Escape)
                    {
                        gameMusic.stop();
                        window.close();
                    }

                   if(Event.key.code == sf::Keyboard::Up || Event.key.code == sf::Keyboard::Down)
                   {
                       if (selector.y == 1)
                       {
                           selector.y = 0;
                           //selectButton(window, 0, 0);

                       }
                       else
                       {
                           selector.y = 1;
                           //selectButton(window, 0, 1);
                       }
                   }

                   if(Event.key.code == sf::Keyboard::Space || Event.key.code == sf::Keyboard::Enter)
                    {
                        if (selector.y == 0)
                        {
                            retry = true;
                        }
                        else if (selector.y == 1)
                        {
                            gameMusic.stop();
                            window.close();
                        }
                    }
            }
        }
    }
}

void GameViewPlayer::selectButton(sf::RenderWindow& window, int y)
{
    if(y == 0)
    {
        retryBtnRec.setTexture(&(loadedTextures->textureArray[12]));
        exitBtnRec.setTexture(&(loadedTextures->textureArray[15]));
    }
    else if(y == 1)
    {
        retryBtnRec.setTexture(&(loadedTextures->textureArray[13]));
        exitBtnRec.setTexture(&(loadedTextures->textureArray[14]));
    }
    updateGame(window);//could this be more optimally placed?
}


void GameViewPlayer::updateSurvivorCount()
{
    string cnt = std::to_string(majorTom->getSurvivors()) + "/20 Survivors";
    survivorCnt.setString(cnt);
}
