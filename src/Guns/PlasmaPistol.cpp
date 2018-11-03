
#include "PlasmaPistol.h"
#include "GameLogic.h"

//instantiate all the basic values for a plasma pistol.
PlasmaPistol::PlasmaPistol(){

}

int PlasmaPistol::getBulletType()
{
    return bulletType;
}

int PlasmaPistol::getShotsFired()
{
    return shotsFired;
}

void PlasmaPistol::shotsFiredPlusOne()
{
    shotsFired++;
}

void PlasmaPistol::resetShotsFired()
{
    shotsFired = 0;
}

int PlasmaPistol::getClipSize()
{
    return clip;
}

float PlasmaPistol::getFireRate()
{
    return fireRate;
}

float PlasmaPistol::getReloadSpeed()
{
    return reloadSpeed;
}

PlasmaPistol::~PlasmaPistol()
{
    //TODO implement destructor
}
