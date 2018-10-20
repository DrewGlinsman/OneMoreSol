/*
 * KoratEmpire.cpp
 *
 *  Created on: Oct 14, 2018
 *      Author: jabowden
 */

#include <KoratEmpire.h>

KoratEmpire::KoratEmpire() {
	// TODO Auto-generated constructor stub

}

KoratEmpire::~KoratEmpire() {
	// TODO Auto-generated destructor stub
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

bool KoratEmpire::checkDeath()
{
    if (this->health <= 0)
        return true;
    return false;
}
