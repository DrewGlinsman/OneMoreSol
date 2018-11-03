
#include "LaserRifle.h"

LaserRifle::LaserRifle() {

}

LaserRifle::~LaserRifle() {
	// TODO Auto-generated destructor stub
}

int LaserRifle::getBulletType()
{
    return bulletType;
}


int LaserRifle::getShotsFired()
{
    return shotsFired;
}

void LaserRifle::shotsFiredPlusOne()
{
    shotsFired++;
}

void LaserRifle::resetShotsFired()
{
    shotsFired = 0;
}

int LaserRifle::getClipSize()
{
    return clip;
}

float LaserRifle::getFireRate()
{
    return fireRate;
}

float LaserRifle::getReloadSpeed()
{
    return reloadSpeed;
}

