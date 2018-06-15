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
    bool can_drop = true;
    for(auto shape_block : active_shape->blocks){
        if(shape_block->y > BOARD_HEIGHT - 2){
            can_drop = false;
            goto after_loop;
        }
        for(auto board_block : blocks){
            if(shape_block->y+1 == board_block->y && shape_block->x == board_block->x){
                can_drop = false;
                goto after_loop;
            }
        }
    }
    after_loop:
    if(can_drop)
        active_shape->drop();
    else
        release_active_shape();
}

void Board::go_left() {
    bool can_go_left = true;
    for(auto block : active_shape->blocks){
        if(block->x - 1 <= -1){
            can_go_left = false;
        }
        for(auto board_block : blocks){
            if(block->x - 1 == board_block->x && block->y == board_block->y){
                can_go_left = false;
            }
        }
    }
    if(can_go_left)
        active_shape->go_left();
}

void Board::go_right() {
    bool can_go_right = true;
    for(auto block : active_shape->blocks){
        if(block->x + 1 >= BOARD_WIDTH){
            can_go_right = false;
        }
        for(auto board_block : blocks){
            if(block->x + 1 == board_block->x && block->y == board_block->y)
                can_go_right = false;
        }
    }
    if(can_go_right)
        active_shape->go_right();
}

void Board::rotate() {
    if(active_shape != nullptr){
        active_shape->rotate();
    }
}

void Board::release_active_shape() {
    for(auto block : active_shape->blocks){
        blocks.push_back(block);
    }
    delete active_shape;
    active_shape = new SquareShape();
}
