CC=g++
CFLAGS = -std=c++17 -Wall -Wextra -Wno-unused-parameter
LFLAGS = -lSDL2 -lSDL2_ttf
NAME = game2048
SRC = game_board.cpp game_handler.cpp highest_score.cpp main.cpp movement.cpp SDL_handler.cpp SDL_printer.cpp view_options.cpp
DEPS = game_board.hpp game_handler.hpp highest_score.hpp movement.hpp SDL_handler.hpp SDL_printer.hpp view_options.hpp
OBJS = game_board.o game_handler.o highest_score.o main.o movement.o SDL_handler.o SDL_printer.o view_options.o

YOU : $(SRC) $(NAME)
$(NAME): $(OBJS)
	 $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	rm -f $(OBJS) $(NAME)
