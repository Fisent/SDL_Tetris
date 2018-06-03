//
// Created by fisent on 03.06.18.
//

#include "TetrisBlock.h"
#include "GlobalConsts.h"

TetrisBlock::TetrisBlock(int x, int y): x(x), y(y){
}

TetrisBlock::TetrisBlock(): x(5), y(0){
}

void TetrisBlock::draw(SDL_Surface *surface) {
    SDL_Rect rect;
    rect.x = x * GRID_SIZE;
    rect.y = y * GRID_SIZE;
    rect.w = GRID_SIZE;
    rect.h = GRID_SIZE;
    SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
}

void TetrisBlock::drop() {
    y++;
}

void TetrisBlock::go_left() {
    x--;
}

void TetrisBlock::go_right() {
    x++;
}
