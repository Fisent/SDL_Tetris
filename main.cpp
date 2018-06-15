#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "src/Block.h"
#include "src/input.handling.h"
#include "src/Board.h"
#include "src/GlobalConsts.h"
#include "src/LTimer.h"


SDL_Window* window = nullptr;
SDL_Surface* surface = nullptr;

Board board;

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

void game_tick(bool& run){
    get_input(run, board);

    board.draw(surface);

    SDL_UpdateWindowSurface(window);
}

int frames_beetwen_drops = 20;

void game_loop(){
    bool run = true;

    LTimer fpsTimer;
    LTimer capTimer;
    int countedFrames = 0;
    int dropdownCounter = frames_beetwen_drops;
    fpsTimer.start();

    board.create_shape();

    while(run){
        capTimer.start();
        float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
//        if (avgFPS > 2000000){
//            avgFPS = 0;
//        }
//        std::cout << "FPS: " << avgFPS << std::endl;
        dropdownCounter--;
        if(dropdownCounter <= 0){
            board.drop();
            dropdownCounter = frames_beetwen_drops;
        }

        game_tick(run);

        ++countedFrames;
        // if frame finished early
        int frameTics = capTimer.getTicks();
        if(frameTics < SCREEN_TICKS_PER_FRAME){
            SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTics);
        }
    }
}


int main(int arg, char** args){

    init();

    game_loop();

    quit();
}
