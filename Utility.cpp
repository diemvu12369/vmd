#include "Utility.h"
#include "Manager.h"

Utility::Utility() {

}
Utility::~Utility() {

}

void Utility::loadMainTexture(const char *texture) {
    objTexture = TextureDrawer::LoadTexture(texture);
}

void Utility::setPosition(int xpos, int ypos) {
    destR.x = xpos;
    destR.y = ypos;
    srcR.h = srcR.w = 1000;
    srcR.x = srcR.y = 0;
    destR.h = 104;
    destR.w = 228;
}


void Utility::Render() {
    SDL_RenderCopy(Manager::renderer, objTexture, nullptr, &destR);
}
void Utility::SrcRender() {
    SDL_RenderCopy(Manager::renderer, objTexture, &srcR, &destR);
}

void Utility::setObjTexture(SDL_Texture *texture) {
    SDL_DestroyTexture(Utility::objTexture);
    Utility::objTexture = texture;
}

