#include "movement.hpp"
#include<bits/stdc++.h>
#include <iostream>

movement::movement(game_board *b)
{
    this->score = score;
    board = b;
    board->reset();
}

void movement::reset()
{
    score = 0;
    board->reset();
    block_2048 = false;
}

int movement::current_score()
{
    return score;
}

bool movement::winning()
{
    return block_2048;
}

bool movement::is_horizontal_pair()
{
    for(int i = 0; i < board->b_size(); i++)
        for(int j = 0; j < board->b_size() - 1; j++)
            if(board->tab[i][j] != 0 && board->tab[i][j] == board->tab[i][j+1])
                return true;
    return false;
}

bool movement::is_vertical_pair()
{
    for(int j = 0; j < board->b_size(); j++)
        for(int i = 0; i < board->b_size() - 1; i++)
            if(board->tab[i][j] != 0 && board->tab[i][j] == board->tab[i+1][j])
                return true;
    return false;
}

bool movement::is_move()
{
    return (!board->is_full() || is_vertical_pair() || is_horizontal_pair());
}

void movement::move_if_else(bool cond, bool &connect_flag, bool &move_flag, int i_0, int j_0, int i_1, int j_1, int di, int dj)
{
    if(cond && !connect_flag && board->tab[i_0][j_0] == board->tab[i_1][j_1])
    {
        board->tab[i_1][j_1] += board->tab[i_0][j_0];
        score += board->tab[i_1][j_1];
        if (board->tab[i_1][j_1] == 2048)
            block_2048 = true;
        board->tab[i_0][j_0] = 0;
        connect_flag = true;
        move_flag = true;
    }
    else
    {
        connect_flag = false;
        if( i_1 != i_0 || j_1 != j_0)
        {
            move_flag = true;
            std::swap(board->tab[i_0][j_0], board->tab[i_1 + di][j_1 + dj]);
        }
    }
}

bool movement::move_right()
{
    bool move_flag = false;
    int N = board->b_size();
    for(int i = 0; i < N; i++)
    {
        bool connect_flag = false;
        for(int j = N-2; j >= 0; j--)
        {
            int t = j+1;
            if(board->tab[i][j] != 0)
            {
                while(t < N && board->tab[i][t] == 0)
                        t++;
                bool cond = t < N;
                move_if_else(cond, connect_flag, move_flag, i, j, i, t, 0, -1);
            }
        }
    }
    return move_flag;
}

bool movement::move_left()
{
    bool move_flag = false;
    int N = board->b_size();
    for(int i = 0; i < N; i++)
    {
        bool connect_flag = false;
        for(int j = 1; j < N; j++)
        {
            int t = j-1;
            if(board->tab[i][j] != 0)
            {
                while(t >= 0 && board->tab[i][t] == 0)
                        t--;
                bool cond = t >= 0;
                move_if_else(cond, connect_flag, move_flag, i, j, i, t, 0, 1);
            }
        }
    }
    return move_flag;
}

bool movement::move_upper()
{
    bool move_flag = false;
    int N = board->b_size();
    for(int j = 0; j < N; j++)
    {
        bool connect_flag = false;
        for(int i = 1; i < N; i++)
        {
            int t = i-1;
            if(board->tab[i][j] != 0)
            {
                while(t >= 0 && board->tab[t][j] == 0)
                        t--;
                bool cond = t >= 0;
                move_if_else(cond, connect_flag, move_flag, i, j, t, j, 1, 0);
            }
        }
    }
    return move_flag;
}

bool movement::move_down()
{
    bool move_flag = false;
    int N = board->b_size();
    for(int j = 0; j < N; j++)
    {
        bool connect_flag = false;
        for(int i = N-2; i >= 0; i--)
        {
            int t = i+1;
            if(board->tab[i][j] != 0)
            {
                while(t < N && board->tab[t][j] == 0)
                        t++;
                bool cond = t < N;
                move_if_else(cond, connect_flag, move_flag, i, j, t, j, -1, 0);
            }
        }
    }
    return move_flag;
}
