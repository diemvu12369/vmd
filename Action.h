#ifndef VMD_ACTION
#define VMD_ACTION

#include <vector>
#include "Utility.h"


class Action : public Utility {
public:
    Action() : Utility() {
        isMoving = true;
        Attacking = false;
        GivingDamage = false;
        Standing = false;
        endOfEvent = true;
        attackDamage = 20;
        attackRange = 40;
        currentAnimation = 0;
        speed = 5;
        health = 50;
        animationDelay = 130;
        flip = SDL_FLIP_NONE;
    }

    ~Action() {};

    int getAttackDamage() const;

    void setAttackDamage(int attackDamage);

    int getAttackRange() const;

    void setAttackRange(int attackRange);

    int getHealth() const;

    void setHealth(int health);;

    int getAttackFrame() const;

    void setAttackFrame(int attackFrame);

    int getBaseAttackDamage() const;

    void setBaseAttackDamage(int baseAttackDamage);

    int getDamageReductionPercentage() const;

    void setDamageReductionPercentage(int damageReductionPercentage);

    int getPrice() const;

    void setPrice(int price);

    void Update();

    void Render();

    void setFlip(SDL_RendererFlip flip);

    void addStandingAnimation(const char *texture);

    void addMovingAnimation(const char *texture);

    void addAttackAnimation(const char *texture);

    void setHitBox(int x, int y, int w, int h);

    void animationUpdate(std::vector<SDL_Texture *> &tmp, bool &cmd);

    void inSight(SDL_Rect x);

    void receiveDamage(int damage);

    void setDirection(int direction);

    bool getEndOfEvent();

    bool isDead();

    SDL_Rect getHitBox();

    bool enemyInRange;

//private:

    bool isMoving;
    bool Attacking;
    bool GivingDamage;
    bool Standing;
    bool endOfEvent;

    int baseAttackDamage;
    int attackDamage;
    int attackRange;
    int attackFrame;
    int damageReductionPercentage;
    int currentAnimation;
    int speed;
    int hitBoxOffsetX, hitBoxOffsetY;
    int health;
    int direction;
    int price;

    SDL_Rect hitBox;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    Uint32 lastAnimationTime = 0;
    Uint32 animationDelay;

    Uint32 getAnimationDelay() const;

    void setAnimationDelay(Uint32 animationDelay);

    std::vector<SDL_Texture *> standingsAnimations;
    std::vector<SDL_Texture *> movingAnimations;
    std::vector<SDL_Texture *> attackingAnimations;
};


#endif
