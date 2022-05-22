#include "Unit.h"
#include "Manager.h"

void Unit::animationUpdate(std::vector<SDL_Texture *> &tmp, bool &cmd) {
    objTexture = tmp[currentAnimation];
    GivingDamage = Attacking && currentAnimation == 4;
    if (currentAnimation + 1 == (int)tmp.size()) {
        cmd = false;
        endOfEvent = true;
        currentAnimation = 0;
        return;
    }
    currentAnimation += 1;
}

void Unit::moveLeft() {
    Flip(SDL_FLIP_HORIZONTAL);
    if (!MovingLeft) {
        MovingLeft = true;
        velocity -= speed;
    }
}

void Unit::stopMovingLeft() {
    if (MovingLeft) {
        MovingLeft = false;
        velocity += speed;
    }
}

void Unit::moveRight() {
    Flip(SDL_FLIP_NONE);
    if (!MovingRight) {
        MovingRight = true;
        velocity += speed;
    }
}

void Unit::stopMovingRight() {
    if (MovingRight) {
        MovingRight = false;
        velocity -= speed;
    }
}

void Unit::Update() {
    if (endOfEvent) {
        if (enemyInRange)
            Attacking = true;
        else
            MovingRight = true;
        endOfEvent = false;
    }

    Uint32 currentTime = SDL_GetTicks();
    if (currentTime >= lastAnimationTime + animationDelay) {
        if(Attacking)
            animationUpdate(stabAnimations, Attacking);
        else if(MovingRight){
            animationUpdate(movingAnimations,MovingRight);
            destR.x += 10;
            hitBox.x = destR.x + hitBoxOffsetX;
        } else
            animationUpdate(standingAnimations, Standing);
        lastAnimationTime = currentTime;
    }
}


void Unit::Render() {
    SDL_RenderCopyEx(Manager::renderer, objTexture, nullptr, &destR, 0, nullptr, flip);
    blade->Render();
}

SDL_Rect Unit::GetFakeHitBox() {
    SDL_Rect ret = hitBox;
    hitBox.x += velocity;
    return ret;
}

void Unit::Flip(SDL_RendererFlip param) {
    flip = param;
}

void Unit::addStandingAnimation(const char *texture) {
    standingAnimations.push_back(TextureDrawer::LoadTexture(texture));
}

void Unit::addMovingAnimation(const char *texture) {
    movingAnimations.push_back(TextureDrawer::LoadTexture(texture));
}

void Unit::addStabAnimation(const char *texture) {
    stabAnimations.push_back(TextureDrawer::LoadTexture(texture));
}

void Unit::addWhirlwindAnimation(const char *texture) {
    whirlwindAnimations.push_back(TextureDrawer::LoadTexture(texture));
}

void Unit::setHitBox(int x, int y, int w, int h) {
    hitBoxOffsetX = x;
    hitBoxOffsetY = y;
    hitBox.h = h;
    hitBox.w = w;
    hitBox.x = destR.x + hitBoxOffsetX;
    hitBox.y = destR.y + hitBoxOffsetY;
}

void Unit::AttackJ() {
    blade->AttackJ(destR.x, destR.y, (flip == SDL_FLIP_HORIZONTAL ? -1 : 1));
}

Weapon *Unit::getblade() const {
    return blade;
}

SDL_Rect Unit::getHitBox() {
    return hitBox;
}

void Unit::receiveDamage(int damage) {
    health -= damage;
}
