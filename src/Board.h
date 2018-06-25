//
// Created by fisent on 03.06.18.
//

#ifndef SDL_TETRIS_BOARD_H
#define SDL_TETRIS_BOARD_H


#include <SDL2/SDL.h>
#include <vector>
#include "Block.h"
#include "Shapes.h"


class Board{
private:
    Shape* active_shape = nullptr;
    void release_active_shape();
    Block* get_block_at(int x, int y);
    int get_index_of_block_at(int x, int y);
    void remove_block_at(int x, int y);

public:
    ~Board();
    std::vector<Block*> blocks;
    void draw(SDL_Surface* surface);
    void create_shape();
    void drop();
    void go_left();
    void go_right();
    void rotate();
    void drop_all_board_above(int dropped_lowest_block);
    void remove_full_rows();
};


#endif //SDL_TETRIS_BOARD_H
