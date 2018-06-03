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
}

Board::~Board() {
    for(TetrisBlock* block : blocks){
        delete block;
    }
}