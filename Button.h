#ifndef VMD_BUTTON
#define VMD_BUTTON

#include "Utility.h"

class Button : public Utility {
public:
    void handleEvents(SDL_Event event);
    void loadActiveTexture(const char *texture);
    void loadInactiveTexture(const char *texture);
    void Render();
    void setActive(bool Active);
    bool isHasOrder() const;
    void setHasOrder(bool hasOrder);

//private:
    bool Active;
    bool hasOrder = false;
    Uint32 timeSinceLastOrder;
    SDL_Texture *inActiveTexture, *activeTexture;
};


#endif
