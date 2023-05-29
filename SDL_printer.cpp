#include <iostream>
#include <string>
#include "SDL_printer.hpp"
#include "game_board.hpp"

SDL_printer::SDL_printer(game_board *board, view_options *opt)
{
    this->board = board;
    this->opt = opt;
    if(opt->background().r + opt->background().g + opt->background().b >= 600)
        scores_c = black;
    SDL_CreateWindowAndRenderer(opt->s_width(), opt->s_height(), 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Game 2048");
    TTF_Init();
}

TTF_Font* SDL_printer::font(int f_size)
{
    TTF_Font *font = TTF_OpenFont(opt->font_f_name().c_str(), f_size);
    if(font == nullptr)
    {
        std::clog << "Cannot use a font from file : " << opt->font_f_name() <<" size "<<f_size<< "\n";
        exit(3);
    }
    return font;
}

void SDL_printer::draw_text(std::string text, SDL_Rect rect, SDL_Color color, TTF_Font* font)
{
    SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, text.c_str(), color);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
    SDL_Rect message_rect;
    TTF_SizeText(font, text.c_str(), &message_rect.w, &message_rect.h);

    message_rect.x = rect.x + rect.w / 2 - message_rect.w / 2;
    message_rect.y = rect.y + rect.h / 2 - message_rect.h / 2;

    SDL_RenderCopy(renderer, Message, NULL, &message_rect);
    SDL_DestroyTexture(Message);
    TTF_CloseFont(font);
    SDL_FreeSurface(surfaceMessage);
}

void SDL_printer::rect_init(SDL_Rect *rect, int x, int y, int w, int h)
{
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
}

SDL_Rect SDL_printer::make_rect(int x, int y, int w, int h, SDL_Color color)
{
    SDL_Rect rect;
    rect_init(&rect, x, y, w, h);
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
    return rect;
}

void SDL_printer::print_board(int w, int h)
{
    int N = board->b_size();

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int l = std::log2(board->value(i,j));
            l = std::max(std::min(l, 10), 0);

            SDL_Rect rect = make_rect((j+1)*w, (i+1)*h, w*0.95, h*0.95, opt->color(l));
            std::string text = std::to_string(board->value(i,j));
            if(text.compare("0") == 0)
                text = "";
            draw_text(text,rect,black,font(block_fs));
        }
}

void SDL_printer::print(int score, int record)
{
    SDL_SetRenderDrawColor(renderer, opt->background().r, opt->background().g, opt->background().b, opt->background().a);
    SDL_RenderClear(renderer);

    int N = board->b_size();
    int w = opt->s_width() / (N + 2);
    int h = opt->s_height() / (N + 2);

    SDL_Rect record_rect = make_rect(w, 0, w, h, opt->background());
    std::string record_text = "Record : " + std::to_string(record);
    draw_text(record_text, record_rect, scores_c, font(scores_fs));

    SDL_Rect score_rect = make_rect(opt->s_width() / 2 + w, 0, w, h, opt->background());
    std::string score_text = "Score : " + std::to_string(score);
    draw_text(score_text, score_rect, scores_c, font(scores_fs));

    print_board(w, h);

    int info_y = h * (N + 1.7);
    int info_w = opt->s_width() / 2;
    int info_h = h * 0.33;
    SDL_Color info_c = {50, 50, 50, 255};

    SDL_Rect info_1_rect = make_rect(0, info_y, info_w, info_h, info_c);
    draw_text("New game - press 'N'", info_1_rect, white, font(info_fs));

    SDL_Rect info_2_rect = make_rect(opt->s_width() / 2, info_y, info_w, info_h, info_c);
    draw_text("End game - press 'Q'", info_2_rect, white, font(info_fs));

    SDL_RenderPresent(renderer);
}

void SDL_printer::print_end(std::string end_message)
{
    TTF_Font *f = font(message_fs);
    TTF_SetFontStyle(f, TTF_STYLE_BOLD);
    SDL_Color color = {255, 0, 127,255};
    SDL_Rect end_rect;
    rect_init(&end_rect, 0, 0, opt->s_width(), opt->s_height());
    draw_text(end_message, end_rect, color, f);
    SDL_RenderPresent( renderer);
}
