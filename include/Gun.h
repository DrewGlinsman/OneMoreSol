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
    float dmgMultipier;
};

#endif // GUN_H
