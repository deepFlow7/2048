#include <iostream>
#include "game_board.hpp"

game_board::game_board()
{
    tab = new int*[N];
    for(int i = 0; i < N; i++)
        tab[i] = new int[N];
}

void game_board::reset()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            tab[i][j] = 0;
}

bool game_board::is_full()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(tab[i][j] == 0)
                return false;
    return true;
}

int game_board::b_size()
{
    return N;
}

int game_board::value(int i, int j)
{
    if(i < 0 || j < 0 || i >= N || j >= N)
    {
        std::clog << "Index out of bounds\n";
        exit(2);
    }
    return tab[i][j];
}

void game_board::new_value(int i, int j, int v)
{
    if(i < 0 || j < 0 || i >= N || j >= N)
    {
        std::clog << "Index out of bounds\n";
        exit(2);
    }
    tab[i][j] = v;
}

