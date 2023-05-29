#include "game_board.hpp"

class movement
{
    game_board *board;
    bool block_2048 = false;
    int score = 0;
    friend class game_handler;

    void move_if_else(bool cond, bool &connect_flag, bool &move_flag, int i_0, int j_0, int i_1, int j_1, int di, int dj);
    bool is_horizontal_pair();
    bool is_vertical_pair();

public :
    movement(game_board *b);
    int current_score();
    void reset();
    bool winning();
    bool is_move();
    bool move_left();
    bool move_right();
    bool move_upper();
    bool move_down();
};
