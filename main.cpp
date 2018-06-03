#include <stdio.h>
#include <SDL2/SDL.h>
#include <algorithm>
#include <iostream>
#include "src/TetrisBlock.h"
#include "src/input.handling.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


SDL_Window* window = nullptr;
SDL_Surface* surface = nullptr;


Uint32 startclock = 0;
Uint32 deltaclock = 0;
Uint32 currentFPS = 0;


bool init(){
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("SDL_first_game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == nullptr){
        printf("Error %s", SDL_GetError());
        return false;
    }
    surface = SDL_GetWindowSurface(window);
    if(surface == nullptr){
        printf("Error %s", SDL_GetError());
    }
    return true;
}


void quit(){
    SDL_FreeSurface(surface);
    SDL_Quit();
}


void game_loop(){
    bool run = true;

    startclock = SDL_GetTicks();

    while(run){
        SDL_Delay(1000/60);
        std::pair<bool, bool> input = get_input(run);
        if(input.first)
            std::cout << "left" << std::endl;
        if(input.second)
            std::cout << "right" << std::endl;

        // FPS calculation
        deltaclock = SDL_GetTicks() - startclock;
        startclock = SDL_GetTicks();
        if(deltaclock != 0)
            currentFPS = 1000 / deltaclock;

        std::cout << "FPS: " << currentFPS << std::endl;
    }
}


int main(int arg, char** args){

    init();

    game_loop();

    quit();
}
