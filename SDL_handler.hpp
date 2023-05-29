#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "game_handler.hpp"
#include "SDL_printer.hpp"

class SDL_handler
{
    bool quit = false;
    SDL_printer *sp;
    game_handler *gh;

    void after_move();

public:
    SDL_handler(view_options *opt);
    void start();
    ~SDL_handler();
};
