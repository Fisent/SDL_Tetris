//
// Created by fisent on 03.06.18.
//

#include <SDL2/SDL.h>
#include <iostream>

const Uint8* keystates = SDL_GetKeyboardState(nullptr);

std::pair<bool, bool> get_input(bool& run){

    std::pair<bool, bool> result;
    result.first = result.second = false;

    //events
    SDL_Event e;
    while(SDL_PollEvent(&e) != 0){
        if(e.type == SDL_QUIT){
            run = false;
        }
    }

    //checking keyboard states

    if(keystates[SDL_SCANCODE_LEFT]){
        result.first = true;
    }
    if(keystates[SDL_SCANCODE_RIGHT]){
        result.second = true;
    }

    return result;
}