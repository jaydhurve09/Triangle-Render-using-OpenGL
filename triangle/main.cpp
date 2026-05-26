#include <SDL3/SDL.h>
#include <iostream>

int main() {
    SDL_Window* window;
    SDL_Surface* surface;
    SDL_Renderer* renderer;
	SDL_Texture* texture;

    if (SDL_Init(SDL_INIT_VIDEO) == false) {
        SDL_Log("SDL_Init failed: %s", SDL_GetError());
        return -1;
    }

    window = SDL_CreateWindow(
        "Triangle",
        320,
        240,
        SDL_WINDOW_RESIZABLE
    );

    if (!window) {
        SDL_Log("Window creation failed: %s", SDL_GetError());
        return -1;
    }

    renderer = SDL_CreateRenderer(window, NULL);

    surface = SDL_LoadBMP("sample.bmp");

    if (!surface) {
        SDL_Log("BMP load failed: %s", SDL_GetError());
        return -1;
    }

    SDL_Log("BMP loaded successfully!");

	texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_Delay(5000);

    SDL_DestroyTexture(texture);
    SDL_DestroySurface(surface);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}