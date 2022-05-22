#ifndef VMD_UNIT
#define VMD_UNIT

#include "Utility.h"
#include "Weapon.h"

class Unit : public Utility {
public:
  Unit() : Utility() {

  };

  void Update();

  void Render();

  void Flip(SDL_RendererFlip param);

  void addStandingAnimation(const char *texture);
  void addMovingAnimation(const char *texture);
  void addStabAnimation(const char *texture);
  void addWhirlwindAnimation(const char *texture);
  void moveLeft();
  void moveRight();
  void stopMovingLeft();
  void stopMovingRight();
  void setHitBox(int x, int y, int w, int h);
  void receiveDamage(int damage);
  void animationUpdate(std::vector<SDL_Texture *> &tmp, bool &cmd);

  int getHealth() {
    return health;
  }

  void setWillBeBlocked(bool tmp) {
    willBeBlocked = tmp;
  }
  bool isDead() {
    return health <= 0;
  }

  SDL_Rect GetFakeHitBox();

  void AttackJ();

private:
  bool endOfEvent;
  bool Attacking;
  bool GivingDamage;
  bool Falling;
  bool Standing;
  bool willBeBlocked;
  bool MovingLeft;
  bool MovingRight;
  bool enemyInRange;

  int currentStatus;
  int currentAnimation;
  int speed = 1;
  int velocity;
  int hitBoxOffsetX, hitBoxOffsetY;
  int health = 70;

  SDL_Rect hitBox;
  SDL_RendererFlip flip = SDL_FLIP_NONE;
  Uint32 timeSinceLastUpdate;
  Uint32 lastAnimationTime;
  Uint32 animationDelay = 200;
  std::vector<SDL_Texture *> standingAnimations;
  std::vector<SDL_Texture *> movingAnimations;
  std::vector<SDL_Texture *> stabAnimations;
  std::vector<SDL_Texture *> whirlwindAnimations;

  Weapon *blade = new Weapon();

public:
  Weapon *getblade() const;

  SDL_Rect getHitBox();
};


#endif
