#include <iostream>

class highest_score
{
    std::string file_name;
    int record = 0;

public:
    highest_score(std::string file_name) : file_name(file_name) {read_record();};
    void read_record();
    void write_record(int new_record);
    int rec();
};
