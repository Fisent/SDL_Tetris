#include <stdio.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int arg, char** args){
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window* window = SDL_CreateWindow("SDL_first_game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Surface* surface = SDL_GetWindowSurface(window);

	bool run = true;

	SDL_Event e;

	while(run){

	    while(SDL_PollEvent(&e) != 0){
	        if(e.type == SDL_QUIT){
	            run = false;
	        }
	    }

        SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));

        SDL_UpdateWindowSurface(window);
	}

    SDL_FreeSurface(surface);
    SDL_Quit();
}
