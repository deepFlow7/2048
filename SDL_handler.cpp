#include "SDL_handler.hpp"

SDL_handler::SDL_handler(view_options *opt)
{
    game_board *b = new game_board();
    gh = new game_handler(b);
    sp = new SDL_printer(b, opt);
    sp->print(gh->mv->current_score(), gh->hs->rec());
}

void SDL_handler::after_move()
{
    gh->add_blocks();
    sp->print(gh->mv->current_score(), gh->hs->rec());
}
void SDL_handler::start()
{
    SDL_Event event;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT :
                quit = true;
                gh->finish_game();
                break;
            case SDL_KEYDOWN :
                switch(event.key.keysym.sym)
                {
                case SDLK_LEFT:
                    if(gh->mv->move_left())
                        after_move();
                    break;
                case SDLK_RIGHT:
                    if(gh->mv->move_right())
                        after_move();
                    break;
                case SDLK_UP:
                    if(gh->mv->move_upper())
                        after_move();
                    break;
                case SDLK_DOWN:
                    if(gh->mv->move_down())
                        after_move();
                    break;
                case SDLK_n :
                {
                    gh->new_game();
                    sp->print(gh->mv->current_score(), gh->hs->rec());
                    break;
                }
                case SDLK_q :
                {
                    quit = true;
                    gh->finish_game();
                    break;
                }
                }
                if(gh->end_of_game())
                {
                    gh->finish_game();
                    sp->print_end(gh->end_message());
                }
            }
        }
    }
}

SDL_handler::~SDL_handler()
{
    TTF_Quit();
    SDL_Quit();
}
