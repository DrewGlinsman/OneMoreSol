
#include "GaussRifle.h"

GaussRifle::GaussRifle() {

}

GaussRifle::~GaussRifle() {
	// TODO Auto-generated destructor stub
}

int GaussRifle::getBulletType()
{
    return bulletType;
}

int GaussRifle::getShotsFired()
{
    return shotsFired;
}

void GaussRifle::shotsFiredPlusOne()
{
    shotsFired++;
}

void GaussRifle::resetShotsFired()
{
    shotsFired = 0;
}

int GaussRifle::getClipSize()
{
    return clip;
}

float GaussRifle::getFireRate()
{
    return fireRate;
}

float GaussRifle::getReloadSpeed()
{
    return reloadSpeed;
}
