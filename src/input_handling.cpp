//
// Created by fisent on 03.06.18.
//

#include <SDL2/SDL.h>
#include <iostream>
#include "input.handling.h"

const Uint8* keystates = SDL_GetKeyboardState(nullptr);

std::pair<bool, bool> get_input(bool& run, Board& board){

    std::pair<bool, bool> result;
    result.first = result.second = false;

    //events
    SDL_Event e;
    while(SDL_PollEvent(&e) != 0){
        if(e.type == SDL_QUIT){
            run = false;
        } else if(e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym){
                case SDLK_LEFT:
                    board.go_left();
                    break;
                case SDLK_RIGHT:
                    board.go_right();
            }
        }
    }

    //checking keyboard states
// for now disabled
//    if(keystates[SDL_SCANCODE_LEFT]){
//        result.first = true;
//    }
//    if(keystates[SDL_SCANCODE_RIGHT]){
//        result.second = true;
//    }

    return result;
}