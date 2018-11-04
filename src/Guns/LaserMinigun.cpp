
#include "LaserMinigun.h"

LaserMinigun::LaserMinigun() {

}

LaserMinigun::~LaserMinigun() {

}

int LaserMinigun::getBulletType()
{
    return bulletType;
}

int LaserMinigun::getShotsFired()
{
    return shotsFired;
}

void LaserMinigun::shotsFiredPlusOne()
{
    shotsFired++;
}

void LaserMinigun::resetShotsFired()
{
    shotsFired = 0;
}

int LaserMinigun::getClipSize()
{
    return clip;
}

float LaserMinigun::getFireRate()
{
    return fireRate;
}

float LaserMinigun::getReloadSpeed()
{
    return reloadSpeed;
}

