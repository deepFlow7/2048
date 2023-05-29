#include <iostream>
#include "SDL2/SDL_ttf.h"

class view_options
{
    int SCREEN_WIDTH = 900;
    int SCREEN_HEIGHT = 900;
    uint8_t red[11], green[11], blue[11];
    SDL_Color background_color;
    std::string font_file_name;

    void check_index(int i);
    void colors_1();
    void colors_2();

public :
    view_options(int width, int height, std::string font_file_name, int color_version, SDL_Color background);
    SDL_Color color(int i);
    std::string font_f_name();
    SDL_Color background();
    int s_width();
    int s_height();
};
