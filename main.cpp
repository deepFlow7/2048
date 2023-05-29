#include <iostream>
#include "SDL_handler.hpp"

void invalid_arguments()
{
    std::clog << "Invalid program's arguments\n";
    exit(1);
}

int main(int argc, char *argv[])
{
    int width = 700, height = 700;
    std::string font_file_name = "Ubuntu-L.ttf";
    int color_version = 1;
    SDL_Color background = {50, 20, 20, 255};
    bool w = false, h = false, f = false, c = false, b = false;

    if(argc >= 2)
    {
        std::string flags = argv[1];
        if(flags[0] != '-' || flags.size() > 6)
            invalid_arguments();
        else
            for(unsigned int i = 1; i < flags.size(); i++)
                switch (flags[i])
                {
                case 'w' :
                    w = true;
                    break;
                case 'h' :
                    h = true;
                    break;
                case 'f' :
                    f = true;
                    break;
                case 'c' :
                    c = true;
                    break;
                case 'b' :
                    b = true;
                    break;
                default :
                    invalid_arguments();
                }

      int s = w + h + f + c + b;
      if(s == 0 || s != (int)flags.size() - 1)
        invalid_arguments();
      if(argc - 2 != s + 2 * b)
        invalid_arguments();
      int read = 2;
      if(w)
      {
            width = atoi(argv[read]);
            read++;
      }
      if(h)
      {
            height = atoi(argv[read]);
            read++;
      }
      if(f)
      {
            font_file_name = argv[read];
            read++;
      }
      if(c)
      {
        color_version = atoi(argv[read]);
        read++;
        if(color_version < 1 || color_version > 2)
            invalid_arguments();
        }
        if(b)
        {
            background = {(Uint8)atoi(argv[read]), (Uint8)atoi(argv[read+1]), (Uint8)atoi(argv[read+2]), 255};
        }
    }

    view_options *opt = new view_options(width, height, font_file_name, color_version, background);
    SDL_handler *sh = new SDL_handler(opt);
    sh->start();
    sh->~SDL_handler();

    return 0;
}
