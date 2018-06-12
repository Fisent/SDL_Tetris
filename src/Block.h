//
// Created by fisent on 03.06.18.
//

#ifndef SDL_FIRST_GAME_TETRISBLOCK_H
#define SDL_FIRST_GAME_TETRISBLOCK_H


#include <SDL2/SDL.h>

class Block {
public:
    int x, y = 0;

    Block(int x, int y);
    void draw(SDL_Surface* surface);
    
};


#endif //SDL_FIRST_GAME_TETRISBLOCK_H
