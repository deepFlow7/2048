#include "SDL2/SDL.h"
#include "view_options.hpp"

class game_board;

class SDL_printer
{
    SDL_Window* window;
    SDL_Renderer *renderer;
    view_options *opt;
    SDL_Color white = {255, 255, 255, 255}, black = {0, 0, 0, 255}, scores_c = white;
    game_board *board;
    int block_fs = 24, scores_fs = 26, info_fs = 20, message_fs = 55;

    TTF_Font* font(int f_size);
    void draw_text(std::string text, SDL_Rect rect, SDL_Color color, TTF_Font* font);
    void rect_init(SDL_Rect *rect, int x, int y, int w, int h);
    SDL_Rect make_rect(int x, int y, int w, int h, SDL_Color color);
    void print_board(int w, int h);

public :
    SDL_printer(game_board *board, view_options *opt);
    void print(int record, int score);
    void print_end(std::string end_message);
};
