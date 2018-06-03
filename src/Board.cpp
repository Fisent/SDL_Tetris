//
// Created by fisent on 03.06.18.
//

#include "Board.h"

void Board::draw(SDL_Surface *surface) {
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));

    for(auto block : blocks){
        block->draw(surface);
    }
}


void Board::create_block() {
    TetrisBlock*  block = new TetrisBlock();
    blocks.push_back(block);
    active_block = block;
}

Board::~Board() {
    for(TetrisBlock* block : blocks){
        delete block;
    }
}

void Board::drop() {
    active_block->drop();
}

void Board::go_left() {
    active_block->go_left();
}

void Board::go_right() {
    active_block->go_right();
}
