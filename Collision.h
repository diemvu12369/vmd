#ifndef VMD_COLLISION
#define VMD_COLLISION

#include "SDL.h"
#include "iostream"

class Collision {
public:
    static bool StrictCollideRect(SDL_Rect a, SDL_Rect b);
    static bool PairCollide(std::pair<int,int> a, std::pair<int,int> b);

    static bool CollideByArea(SDL_Rect a, SDL_Rect b);
};


#endif
