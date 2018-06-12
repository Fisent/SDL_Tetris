//
// Created by fisent on 03.06.18.
//

#include <iostream>
#include "Board.h"
#include "GlobalConsts.h"

void Board::draw(SDL_Surface *surface) {
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));

    for(auto block : blocks){
        block->draw(surface);
    }


    if(active_shape != nullptr){
        active_shape->draw(surface);
    }
}

void Board::create_shape() {
    Shape* shape = new SquareShape();
    active_shape = shape;
}

Board::~Board() {
    for(Block* block : blocks){
        delete block;
    }
}

void Board::drop() {
    // TODO whether
    active_shape->drop();
}

void Board::go_left() {
    bool can_go_left = true;
    for(auto block : active_shape->blocks){
        can_go_left = can_go_left && block->x - 1 > -1;
    }
    if(can_go_left)
        active_shape->go_left();
}

void Board::go_right() {
    bool can_go_right = true;
    for(auto block : active_shape->blocks){
        can_go_right = can_go_right && block->x + 1 < BOARD_WIDTH;
    }
    if(can_go_right)
        active_shape->go_right();
}

void Board::rotate() {
    if(active_shape != nullptr){
        active_shape->rotate();
    }
}
