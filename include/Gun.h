#ifndef GUN_H
#define GUN_H


class Gun
{
public:
    Gun();
    virtual ~Gun();

protected:

private:
    unsigned int damage;
    unsigned int clip;
};

#endif // GUN_H
