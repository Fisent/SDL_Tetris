//
// Created by fisent on 03.06.18.
//

#include "Block.h"
#include "GlobalConsts.h"

Block::Block(int x, int y): x(x), y(y){
}


void Block::draw(SDL_Surface *surface) {
    SDL_Rect rect;
    rect.x = x * GRID_SIZE;
    rect.y = y * GRID_SIZE;
    rect.w = GRID_SIZE;
    rect.h = GRID_SIZE;
    SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
}
