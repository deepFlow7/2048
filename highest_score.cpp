#include <fstream>
#include "highest_score.hpp"

void highest_score::read_record()
{
    std::ifstream in;
    in.open(file_name);
    if(in.fail())
        std::clog << "Cannot open file '" << file_name << "'. Highest score = 0.\n";
    else
    {
        in >> record;
        if(record < 0)
            record = 0;
    }
    in.close();
}

void highest_score::write_record(int new_record)
{
    std::ofstream out;
    out.open(file_name);
    if(out.fail())
        std::clog << "Cannot save new record.\n";
    else
        out << new_record;
    out.close();
    record = new_record;
}

int highest_score::rec()
{
    return record;
}




