#include "highest_score.hpp"
#include "movement.hpp"

class game_handler
{
    highest_score *hs;
    movement *mv;

    int random_number(int from, int to);
    int random_block();
    friend class SDL_handler;

public :
    game_handler(game_board *b);
    void new_game();
    void finish_game();
    bool end_of_game();
    std::string end_message();
    void add_blocks();
};
