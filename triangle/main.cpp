#include <iostream>
#include <SDL3/SDL.h>

int main() {
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("SDL_Init failed: %s", SDL_GetError());
		return -1;
	}


	// Create a window with the title "Triangle", dimensions 320x240, and make it resizable.
	SDL_Window* window = SDL_CreateWindow("Triangle", 320, 240, SDL_WINDOW_RESIZABLE);

	SDL_Delay(10000);

	SDL_Quit();
}