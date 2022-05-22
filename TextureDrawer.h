#ifndef VMD_DRAWER
#define VMD_DRAWER

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"


class TextureDrawer {
public:
    TextureDrawer();

    static SDL_Texture *LoadTexture(const char *fileName);

    static void Draw(SDL_Texture *tex, const SDL_Rect &srcR, const SDL_Rect &destR);

    static SDL_Texture *loadNumber(int number, SDL_Rect &rect, int size);

    static SDL_Texture *loadText(const char *text, SDL_Rect &rect);
};


#endif
