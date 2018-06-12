//
// Created by fisent on 12.06.18.
//

#include "Shapes.h"

void Shape::go_left() {
    for(auto block : blocks){
        block->x--;
    }
}

void Shape::go_right() {
    for(auto block : blocks){
        block->x++;
    }
}

Shape::Shape() {

}

void Shape::drop() {
    for(auto block : blocks){
        block->y++;
    }
}

SquareShape::SquareShape(){
    blocks.push_back(new Block(5, 0));
    blocks.push_back(new Block(6, 0));
    blocks.push_back(new Block(5, 1));
    blocks.push_back(new Block(6, 1));
}

void SquareShape::draw(SDL_Surface* surface) {
    for(auto block : blocks){
        block->draw(surface);
    }
}

void SquareShape::rotate() {

}
