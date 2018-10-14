#ifndef GUN_H
#define GUN_H


class Gun
{
public:
    Gun();
    virtual ~Gun();
    unsigned int damage;
    unsigned int clip;
    float reloadSpeed;
    float dmgMultiplier;
    float fireRate;
};

#endif // GUN_H
