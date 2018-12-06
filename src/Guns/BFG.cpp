
#include "BFG.h"

BFG::BFG() = default;

BFG::~BFG() = default;

int BFG::getBulletType()
{
    return bulletType;
}

int BFG::getShotsFired()
{
    return shotsFired;
}

void BFG::shotsFiredPlusOne()
{
    shotsFired++;
}

void BFG::resetShotsFired()
{
    shotsFired = 0;
}

int BFG::getClipSize()
{
    return clip;
}

float BFG::getFireRate()
{
    return fireRate;
}

float BFG::getReloadSpeed()
{
    return reloadSpeed;
}

