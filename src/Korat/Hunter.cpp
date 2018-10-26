
#include "Hunter.h"
#include <iostream>

Hunter::Hunter(int startLane, TextureLoader* loadedTextures){
    lane = 0;

	hunter.setTexture(loadedTextures->mtSpriteSheet);
	hunter.setTextureRect(sf::IntRect(0,640,64,64));
	hunter.setOrigin(sf::Vector2f(32.f,32.f));
	setLane(startLane);
	hunter.setPosition(1500, lane);
	std::cout << "I'm a hunter" << std::endl;
}

Hunter::~Hunter() {
	// TODO Auto-generated destructor stub

}

void Hunter::wasShot(int damage)
{
	health - damage;
	if(health < 0)
    {
        //trigger hunter death
    }
}

int Hunter::getLane()
{
    return lane;
}

void Hunter::setLane(int givenLane)
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

void Hunter::moveCurrentKorat(float timePassed)
{
        if(hunter.getPosition().x > 500)
        {
            hunter.move(-speed * timePassed, 0);
        }
        else
        {
            health = 0;
        }
}

void Hunter::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(hunter);
}

sf::Sprite Hunter::getKorat()
{
    return hunter;
}

bool Hunter::checkDeath()
{
    if (health <= 0)
        return true;
    return false;
}
