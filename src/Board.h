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
    void physic_frame();
};


#endif //SDL_TETRIS_BOARD_H
