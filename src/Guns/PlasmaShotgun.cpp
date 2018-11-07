
#include "PlasmaShotgun.h"

PlasmaShotgun::PlasmaShotgun() {

}

PlasmaShotgun::~PlasmaShotgun() {

}

int PlasmaShotgun::getBulletType()
{
    return bulletType;
}

int PlasmaShotgun::getShotsFired()
{
    return shotsFired;
}

void PlasmaShotgun::shotsFiredPlusOne()
{
    shotsFired++;
}

void PlasmaShotgun::resetShotsFired()
{
    shotsFired = 0;
}

int PlasmaShotgun::getClipSize()
{
    return clip;
}

float PlasmaShotgun::getFireRate()
{
    return fireRate;
}

float PlasmaShotgun::getReloadSpeed()
{
    return reloadSpeed;
}
