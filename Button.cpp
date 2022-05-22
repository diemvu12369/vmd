#include "Button.h"
#include "Manager.h"

void Button::loadActiveTexture(const char *texture) {
    activeTexture = TextureDrawer::LoadTexture(texture);
}

void Button::loadInactiveTexture(const char *texture) {
    inActiveTexture = TextureDrawer::LoadTexture(texture);
}

void Button::Render() {
    SDL_RenderCopy(Manager::renderer, Active ? activeTexture : inActiveTexture, nullptr, &destR);
}

void Button::handleEvents(SDL_Event event) {
    hasOrder = false;
    switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
            int xpos, ypos;
            SDL_GetMouseState(&xpos, &ypos);
            if (destR.x <= xpos && xpos <= destR.x + destR.w &&
                destR.y <= ypos && ypos <= destR.y + destR.h) {
                if (Active)
                    hasOrder = true;
            }
            break;
        default:
            break;
    }
}

void Button::setActive(bool Active) {
    Button::Active = Active;
}

bool Button::isHasOrder() const {
    return hasOrder;
}

void Button::setHasOrder(bool hasOrder) {
    Button::hasOrder = hasOrder;
}
