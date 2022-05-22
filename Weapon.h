#ifndef VMD_WEAPON
#define VMD_WEAPON

#include "Utility.h"
#include "vector"

class Weapon : public Utility {
public:
    Weapon();

    ~Weapon();

    void addAnimation(const char *texture);

    void AttackJ(int xpos, int ypos,int direction);

    void Update();

    int getAttackStatus(){
        return Attacking;
    }

private:
    void ReleaseWhirlWind();

private:
    int direction;
    int Attacking;
    int jStack;
    int damage;
    int currentAnimation;
    Uint32 lastAttackTime=0;
    Uint32 lastAnimationTime;
    Uint32 coolDown = 1500;
    Uint32 animationDelay;
    std::vector<SDL_Texture *> animations;

};


#endif
