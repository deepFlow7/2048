#include "view_options.hpp"
#include <cstring>

view_options::view_options(int width, int height, std::string font_file_name, int colors_version, SDL_Color background)
{
    if(width >= 400 && width <= 1000)
        SCREEN_WIDTH = width;
    if(height >= 400 && height <= 1000)
        SCREEN_HEIGHT = height;
    background_color = background;
    this->font_file_name = font_file_name;
    if(colors_version == 2)
        colors_2();
    else
        colors_1();
}

void view_options::colors_1()
{
    uint8_t r_color[11] = {224, 255, 255, 255, 229, 204, 204, 204, 255, 255, 204};
    uint8_t g_color[] =   {224, 229, 200, 204, 204, 255, 255, 229, 204, 204, 204};
    uint8_t b_color[] =   {224, 204, 190, 229, 255, 255, 229, 255, 204, 255, 255};

    memcpy(red, r_color, 11*sizeof(uint8_t));
    memcpy(green, g_color, 11*sizeof(uint8_t));
    memcpy(blue, b_color, 11*sizeof(uint8_t));
}

void view_options::colors_2()
{
    uint8_t r_color[11] = {224, 255, 255, 255, 220, 240, 188,  10, 255, 218, 219};
    uint8_t g_color[] =   {224, 255, 210, 218, 100, 230, 143, 153, 192, 165, 112};
    uint8_t b_color[] =   {224, 200, 210, 175, 100, 140, 143, 153, 203,  32, 147};

    memcpy(red, r_color, 11*sizeof(uint8_t));
    memcpy(green, g_color, 11*sizeof(uint8_t));
    memcpy(blue, b_color, 11*sizeof(uint8_t));
}

void view_options::check_index(int i)
{
    if(i < 0 || i > 10)
    {
        std::clog << "Index out of bounds";
        exit(2);
    }
}

SDL_Color view_options::color(int i)
{
    check_index(i);
    SDL_Color c = {red[i], green[i], blue[i], 255};
    return c;
}

std::string view_options::font_f_name()
{
    return font_file_name;
}

SDL_Color view_options::background()
{
    return background_color;
}

int view_options::s_width()
{
    return SCREEN_WIDTH;
}

int view_options::s_height()
{
    return SCREEN_HEIGHT;
}

