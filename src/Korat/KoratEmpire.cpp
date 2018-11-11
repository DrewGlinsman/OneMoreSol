/*
 * KoratEmpire.cpp
 */

#include <KoratEmpire.h>

KoratEmpire::KoratEmpire(int startLane, TextureLoader* loadedTextures){
}
//empty override
KoratEmpire::KoratEmpire(){
}

KoratEmpire::~KoratEmpire() {
	// TODO Auto-generated destructor stub
}

void KoratEmpire::wasShot(int damage)
{

}

void KoratEmpire::setLane(int givenLane)
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

int KoratEmpire::getLane()
{
    return lane;
}

std::string KoratEmpire::getName()
{

}

void KoratEmpire::incrementRunFrame(sf::IntRect* sF, sf::Sprite* baddie)
{
    sF->left = (sF->left+64)%192;
    baddie->setTextureRect(*sF);
}

void KoratEmpire::moveCurrentKorat(float timepassed)
{
    //incrementRunFrame(&spriteFrame, &korat);
}

void KoratEmpire::drawCurrentKorat(sf::RenderWindow& window)
{
    window.draw(korat);
}

sf::Sprite KoratEmpire::getKorat()
{
    return korat;
}

float KoratEmpire::getPositionX()
{
    return korat.getPosition().x;
}

int KoratEmpire::getHealth()
{
    return health;
}

bool KoratEmpire::checkDeath()
{

}

bool KoratEmpire::checkSurvive()
{
    return survive;
}

int KoratEmpire::getSpeed()
{
    return speed;
}
