#include "TextureDrawer.h"
#include "Manager.h"

TextureDrawer::TextureDrawer() {

}

SDL_Texture *TextureDrawer::LoadTexture(const char *fileName) {
  SDL_Surface *tmp = IMG_Load(fileName);
  SDL_Texture *tex = SDL_CreateTextureFromSurface(Manager::renderer, tmp);
  SDL_FreeSurface(tmp);
  return tex;
}

void TextureDrawer::Draw(SDL_Texture *tex, const SDL_Rect &srcR, const SDL_Rect &destR) {
  SDL_RenderCopy(Manager::renderer, tex, nullptr, &destR);
}

SDL_Texture *TextureDrawer::loadNumber(int integer, SDL_Rect &rect, int size) {
  TTF_Font *font = TTF_OpenFont("fonts/coolvetica.ttf", size);
  SDL_Surface *surface = TTF_RenderText_Solid(font, std::to_string(integer).c_str(), {250, 250, 250});
  SDL_Texture *texture = SDL_CreateTextureFromSurface(Manager::renderer, surface);
  rect.w = surface->w;
  rect.h = surface->h;
  SDL_FreeSurface(surface);
  TTF_CloseFont(font);
  return texture;
}

SDL_Texture *TextureDrawer::loadText(const char *text, SDL_Rect &rect) {
  TTF_Font *font = nullptr;
  font = TTF_OpenFont("fonts/coolvetica.ttf", 24);
  SDL_Color color = {250, 250, 250};
  SDL_Surface *surface = TTF_RenderText_Solid(font, text, color);
  rect.w = surface->w;
  rect.h = surface->h;
  SDL_Texture *texture = SDL_CreateTextureFromSurface(Manager::renderer, surface);
  SDL_FreeSurface(surface);
  TTF_CloseFont(font);
  return texture;
}

