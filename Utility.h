#ifndef VMD_UTILITY
#define VMD_UTILITY

#include "TextureDrawer.h"

class Utility {
public:
    //Utility(const char *texture, int xpos, int ypos);
    Utility();

    ~Utility();

    void loadMainTexture(const char *texture);

    void setPosition(int xpos, int ypos);

    void setDestR(int x, int y, int w, int h) {
        destR.x = x;
        destR.y = y;
        destR.w = w;
        destR.h = h;
    }

    void setSrcR(int x, int y, int w, int h) {
        srcR.x = x;
        srcR.y = y;
        srcR.w = w;
        srcR.h = h;
    }

    void Render();
    void SrcRender();

//protected:
public:
    SDL_Texture *objTexture;

    void setObjTexture(SDL_Texture *objTexture);

    SDL_Rect srcR;
    SDL_Rect destR;
};


#endif
