#ifndef BULLET_H
#define BULLET_H


class Bullet
{
    public:
        Bullet();
        virtual ~Bullet();

        float getVelocity();
        void setVelocity(float);

    protected:

    private:
        //damage
        float damage;

        //speed
        float velocity;

        //location
        float positionX;
        float positionY;
};

#endif // BULLET_H
