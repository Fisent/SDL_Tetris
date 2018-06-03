//
// Created by fisent on 03.06.18.
//

#ifndef SDL_FIRST_GAME_TETRISBLOCK_H
#define SDL_FIRST_GAME_TETRISBLOCK_H


#include <SDL2/SDL.h>

class TetrisBlock {
int x, y;

public:
    TetrisBlock(int x, int y);
    TetrisBlock();
    void draw(SDL_Surface* surface);
};


#endif //SDL_FIRST_GAME_TETRISBLOCK_H
