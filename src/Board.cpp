//
// Created by fisent on 03.06.18.
//

#include "Board.h"

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
    active_shape->drop();
}

void Board::go_left() {
    active_shape->go_left();
}

void Board::go_right() {
    active_shape->go_right();
}
