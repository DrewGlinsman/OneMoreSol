/*
 * KoratEmpire.cpp
 */

#include <KoratEmpire.h>

KoratEmpire::KoratEmpire(int startLane) {
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

/** \brief
 * Frame looping function to run animations for standard sized sprites.
 * Set up for a 3 frame loop.
 * \param sf::IntRect*
 * \param sf::Sprite*
 * \return void
 *
 */
void KoratEmpire::incrementRunFrame(sf::IntRect* sF, sf::Sprite* baddie)
{
    sF->left = (sF->left+64)%192;
    baddie->setTextureRect(*sF);
}

/** \brief
 * Frame looping function to run longer boss animations for boss sized sprites.
 * Set up for a 5 frame loop.
 * \param sf::IntRect*
 * \param sf::Sprite*
 * \return void
 *
 */
void KoratEmpire::incrementRunFrame5(sf::IntRect* sF, sf::Sprite* baddie)
{
    sF->left = (sF->left+64)%320;
    baddie->setTextureRect(*sF);
}

//NOTE: DOESNT WORK it references it's own korat sprite, which is blank.
//need to implement xml reading to give it a specific coordinate to
//assign sprites by type. otherwise korat would only be 1 type if
//implemented here.
void KoratEmpire::moveCurrentKorat(float timePassed)
{
    if(korat.getPosition().x > -100)
    {
        korat.move(-speed * timePassed, 0);
        incrementRunFrame(&spriteFrame, &korat);
    }
    else
        survive = true;
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

void KoratEmpire::setFireRate()
{

}

double KoratEmpire::getFireRate()
{

}

bool KoratEmpire::queryToFire()
{

}
