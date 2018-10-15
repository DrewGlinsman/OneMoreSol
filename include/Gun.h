#ifndef GUN_H
#define GUN_H
#include<SFML/Graphics.hpp>

class Gun
{
public:
    Gun();
    virtual ~Gun();
<<<<<<< HEAD

=======
>>>>>>> refs/heads/master
    unsigned int damage;
    unsigned int clip;
    float reloadSpeed;
<<<<<<< HEAD
    std::string dmgMultiplier;
    float fireRate;
    sf::Image image;

=======
    float dmgMultiplier;
    float fireRate;
>>>>>>> refs/heads/master
};

#endif // GUN_H
