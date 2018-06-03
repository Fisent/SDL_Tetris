//
// Created by fisent on 03.06.18.
//

#ifndef SDL_TETRIS_BOARD_H
#define SDL_TETRIS_BOARD_H


#include <SDL2/SDL.h>
#include <vector>
#include "TetrisBlock.h"


class Board {
private:
    TetrisBlock* active_block = nullptr;

public:
    ~Board();
    std::vector<TetrisBlock*> blocks;
    void draw(SDL_Surface* surface);
    void create_block();
    void drop();
    void go_left();
    void go_right();
};


#endif //SDL_TETRIS_BOARD_H
