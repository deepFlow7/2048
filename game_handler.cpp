#include "game_handler.hpp"
#include <string>
#include <vector>
#include <random>

game_handler::game_handler(game_board *b)
{
    hs = new highest_score("record.txt");
    mv = new movement(b);
    add_blocks();
}

void game_handler::new_game()
{
    if(mv->current_score() > hs->rec())
        hs->write_record(mv->current_score());
    mv->reset();
    add_blocks();
}

void game_handler::finish_game()
{
    if(mv->current_score() > hs->rec())
        hs->write_record(mv->current_score());
}

std::string game_handler::end_message()
{
    std::string message = "Game over, you ";
    if(mv->winning())
        message.append("win!");
    else
        message.append("lose!");
    return message;
}

bool game_handler::end_of_game()
{
    return !mv->is_move();
}

int game_handler::random_number(int from, int to)
{
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(from,to);
    return dist(rng);
}

int game_handler::random_block()
{
    return 2*random_number(1,2);
}

void game_handler::add_blocks()
{
    std::vector < std::pair <int,int> > empty_fields;

    for(int i = 0; i < mv->board->b_size(); i++)
        for(int j = 0; j < mv->board->b_size(); j++)
            if (mv->board->value(i,j) == 0)
                empty_fields.push_back(std::make_pair(i,j));

    int n = empty_fields.size();
    if(n == 1)
    {
        std::pair <int, int> added = empty_fields[0];
        mv->board->new_value(added.first, added.second, random_block());
    }
    if(n > 1)
    {
        std::pair <int, int> added_1, added_2;
        int poz_1 = random_number(0,n-1);
        added_1 = empty_fields[poz_1];
        empty_fields.erase(empty_fields.begin() + poz_1);
        int poz_2 = random_number(0,n-2);
        added_2 = empty_fields[poz_2];

        mv->board->new_value(added_1.first, added_1.second, random_block());
        mv->board->new_value(added_2.first, added_2.second, random_block());
    }
}

