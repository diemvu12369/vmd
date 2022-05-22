#include "Action.h"
#include "Manager.h"


bool Action::getEndOfEvent() {
    return Action::endOfEvent;
}

SDL_Rect Action::getHitBox() {
    return Action::hitBox;
}

bool Action::isDead() {
    return Action::health <= 0;
}

void Action::setDirection(int direction) {
    Action::direction = direction;
}


void Action::animationUpdate(std::vector<SDL_Texture *> &tmp, bool &cmd) {
    objTexture = tmp[currentAnimation];
    GivingDamage = Attacking && currentAnimation == attackFrame;
    if (currentAnimation + 1 == (int)tmp.size()) {
        cmd = false;
        endOfEvent = true;
        currentAnimation = 0;
        return;
    }
    currentAnimation += 1;
}

void Action::inSight(SDL_Rect x) {
    SDL_Rect tmp = hitBox;
    tmp.x += attackRange * direction;
    tmp.w += attackRange;
    if (Collision::StrictCollideRect(x, tmp)) {
        enemyInRange = true;
    }
}

void Action::Update() {
    if (endOfEvent) {
        if (enemyInRange) {
            Attacking = true;
            attackDamage = baseAttackDamage;
        }
        else
            isMoving = true;
        endOfEvent = false;
    }
    Uint32 currentTime = SDL_GetTicks();
    if (currentTime >= lastAnimationTime + animationDelay) {
        if (Attacking)
            animationUpdate(attackingAnimations, Attacking);
        else if (isMoving) {
            animationUpdate(movingAnimations, isMoving);
            destR.x += speed * direction;
            hitBox.x = destR.x + hitBoxOffsetX;
        } else
            animationUpdate(standingsAnimations, Standing);
        lastAnimationTime = currentTime;
    }
}

void Action::receiveDamage(int damage) {
    health -= damage;
}

void Action::setFlip(SDL_RendererFlip flip) {
    Action::flip = flip;
}

void Action::Render() {
    //SDL_RenderCopy(Manager::renderer, objTexture, nullptr, &destR);
    //SDL_RenderCopy(Manager::renderer, objTexture, nullptr, &destR);
    SDL_RenderCopyEx(Manager::renderer, objTexture, nullptr, &destR, 0, nullptr, flip);
}

void Action::addStandingAnimation(const char *texture) {
    standingsAnimations.push_back(TextureDrawer::LoadTexture(texture));
}

void Action::addMovingAnimation(const char *texture) {
    movingAnimations.push_back(TextureDrawer::LoadTexture(texture));
}

void Action::addAttackAnimation(const char *texture) {
    attackingAnimations.push_back(TextureDrawer::LoadTexture(texture));
}

void Action::setHitBox(int x, int y, int w, int h) {
    hitBoxOffsetX = x;
    hitBoxOffsetY = y;
    hitBox.x = destR.x + hitBoxOffsetX;
    hitBox.y = destR.y + hitBoxOffsetY;
    hitBox.h = h;
    hitBox.w = w;
}

int Action::getAttackDamage() const {
    return attackDamage;
}

void Action::setAttackDamage(int attackDamage) {
    Action::attackDamage = attackDamage;
}

int Action::getAttackRange() const {
    return attackRange;
}

void Action::setAttackRange(int attackRange) {
    Action::attackRange = attackRange;
}

int Action::getHealth() const {
    return health;
}

void Action::setHealth(int health) {
    Action::health = health;
}

int Action::getAttackFrame() const {
    return attackFrame;
}

void Action::setAttackFrame(int attackFrame) {
    Action::attackFrame = attackFrame;
}

int Action::getBaseAttackDamage() const {
    return baseAttackDamage;
}

void Action::setBaseAttackDamage(int baseAttackDamage) {
    Action::baseAttackDamage = baseAttackDamage;
}

int Action::getDamageReductionPercentage() const {
    return damageReductionPercentage;
}

void Action::setDamageReductionPercentage(int damageReductionPercentage) {
    Action::damageReductionPercentage = damageReductionPercentage;
}

Uint32 Action::getAnimationDelay() const {
    return animationDelay;
}

void Action::setAnimationDelay(Uint32 animationDelay) {
    Action::animationDelay = animationDelay;
}

int Action::getPrice() const {
    return price;
}

void Action::setPrice(int price) {
    Action::price = price;
}
