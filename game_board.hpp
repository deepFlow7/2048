class game_board
{
    const int N = 4;
    int **tab;
    friend class movement;
 public :
    game_board();
    void reset();
    bool is_full();
    int b_size();
    int value(int i, int j);
    void new_value(int i, int j, int v);
};
