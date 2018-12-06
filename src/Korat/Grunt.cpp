
#include "Grunt.h"
#include <iostream>

Grunt::Grunt(int startLane, TextureLoader* loadedTextures){
    lane = 0;

	grunt.setTexture(loadedTextures->textureArray[0]);
	spriteFrame.left = 0;//x
	spriteFrame.top = 448;//y
	spriteFrame.width = 64;
	spriteFrame.height = 64;
	grunt.setTextureRect(spriteFrame);

	grunt.setOrigin(sf::Vector2f(32.f, 32.f));
	setLane(startLane);
	grunt.setPosition(1500, lane);
	grunt.setScale(sf::Vector2f(1.2f,1.2f));
}

Grunt::~Grunt() {
	// TODO Auto-generated destructor stub

}

void Grunt::wasShot(int damage)
{
	health = health - damage;

}

std::string Grunt::getName()
{
    return "Grunt";
}

void Grunt::moveCurrentKorat(float timePassed)
{
        if(grunt.getPosition().x > -100)
        {
            grunt.move(-speed * timePassed, 0);
            if(!((int)grunt.getPosition().x % 10))
                KoratEmpire::incrementRunFrame(&spriteFrame, &grunt);
        }
        else
        {
            survive = true;
        }
}

bool Grunt::checkDeath()
{
    if (health <= 0)
    {
		postDeathTime = postDeathClock.getElapsedTime().asSeconds();
		if (postDeathTime >= .5)
		{
			postDeathClock.restart();
			return true;
		}
		else
        {
			speed = 0;
			if (!koratDeathSoundPlayed)
			{
				postDeathClock.restart();
				koratDeathSoundPlayed = true;
			}

			//death animation
			spriteFrame.left = 192;//x
            spriteFrame.top = 448;//y
            spriteFrame.width = 64;
            spriteFrame.height = 64;
            grunt.setTextureRect(spriteFrame);
			return false;
		}
    }
    else
    {
        postDeathClock.restart();
        return false;

    }
}
    //should be in korat empire as nothing changes between classes
    void Grunt::setLane (int givenLane)
    {
        switch(givenLane)
        {
            case 1:
                lane = lane1;
                break;
            case 2:
                lane = lane2;
                break;
            case 3:
                lane = lane3;
                break;
            case 4:
                lane = lane4;
                break;
            case 5:
                lane = lane5;
                break;
            default:
                lane = lane1;
                break;
        }
    }

    int Grunt::getLane()
    {
        return lane;
    }

    void Grunt::drawCurrentKorat(sf::RenderWindow& window)
    {
        window.draw(grunt);
    }

    sf::Sprite Grunt::getKorat()
    {
        return grunt;
    }

    float Grunt::getPositionX()
    {
        return grunt.getPosition().x;
    }

    int Grunt::getHealth()
    {
        return health;
    }
    bool Grunt::checkSurvive()
    {
        return survive;
    }

    int Grunt::getSpeed()
    {
        return speed;
    }
