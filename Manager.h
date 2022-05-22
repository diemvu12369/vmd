#ifndef VMD_MANAGER
#define VMD_MANAGER

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <iostream>

#include "Collision.h"
#include "Unit.h"

struct Manager {
    Manager();
    ~Manager();

    void init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen);

    void drawMenu();
    void handleMenuEvents();
    void updateMenu();
    bool running();
    void handleEvents();
    void update();
    void render();
    void clean();
    static SDL_Renderer *renderer;

    bool is_running = true;
    bool is_at_menu = true;
    bool is_over = false;
    SDL_Window *window;
};

#endif


