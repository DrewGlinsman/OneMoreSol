
#include "ArcThrower.h"

ArcThrower::ArcThrower(){

}

ArcThrower::~ArcThrower() {
	// TODO Auto-generated destructor stub
}

int ArcThrower::getBulletType()
{
    return bulletType;
}

int ArcThrower::getShotsFired()
{
    return shotsFired;
}

void ArcThrower::shotsFiredPlusOne()
{
    shotsFired++;
}

void ArcThrower::resetShotsFired()
{
    shotsFired = 0;
}

int ArcThrower::getClipSize()
{
    return clip;
}

float ArcThrower::getFireRate()
{
    return fireRate;
}

float ArcThrower::getReloadSpeed()
{
    return reloadSpeed;
}


