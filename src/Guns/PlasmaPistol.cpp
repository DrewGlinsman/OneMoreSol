
#include "PlasmaPistol.h"

//instantiate all the basic values for a plasma pistol.
PlasmaPistol::PlasmaPistol()
{
    bulletType = 1;
    fireRate = 0.5;
    clip = 10;
    damage = 5;
    dmgMultiplier = 2;
    reloadSpeed = 1.5;
    //TODO set the image to the PlasmaPistol sprite.
}

void PlasmaPistol::shoot()
{

    //TODO make shoot spawn a bullet object in the correct lane and communicate back
    //the bullet to be drawn, also use fireRate to limit the shooting to a certain speed.
}

void PlasmaPistol::reload()
{
    //TODO make reload take the right amount of time and update the UI feedback.
}

PlasmaPistol::~PlasmaPistol()
{
    //TODO implement destructor
}
