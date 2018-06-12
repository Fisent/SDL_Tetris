//
// Created by fisent on 12.06.18.
//

#ifndef SDL_TETRIS_SHAPES_H
#define SDL_TETRIS_SHAPES_H


#include "Block.h"
#include <vector>

class Shape {
public:
    Shape();
    virtual void draw(SDL_Surface* surface) = 0;
    void go_left();
    void go_right();
    void drop();

    std::vector<Block*> blocks;
};

class SquareShape : public Shape{
public:
    SquareShape();
    void  draw(SDL_Surface* surface) override;
};


#endif //SDL_TETRIS_SHAPES_H
