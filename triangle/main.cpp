	#include <SDL3/SDL.h>

	void initialize() {
		if (!SDL_Init(SDL_INIT_VIDEO)) {
			SDL_Log("SDL_Init() faild: %s", SDL_GetError());
		}
	}

	void createWindow(SDL_Window*& window) {
		window = SDL_CreateWindow("Triangle Window", 380, 240, SDL_WINDOW_RESIZABLE);
	}

	void createSurface(SDL_Surface*& surface) {
		surface = SDL_LoadBMP("sample.bmp");
	}

	void CreateRender(SDL_Renderer*& renderer, SDL_Window* window) {
		renderer = SDL_CreateRenderer(window, NULL);
	}

	void CreateTexture(SDL_Texture*& texture, SDL_Renderer* renderer, SDL_Surface* surface) {
		texture = SDL_CreateTextureFromSurface(renderer, surface);
	}

	void cleanup(SDL_Window* window, SDL_Surface* surface, SDL_Renderer* renderer, SDL_Texture* texture) {
		SDL_DestroyTexture(texture);
		SDL_DestroySurface(surface);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	int main() {
		SDL_Window* window = NULL;
		SDL_Surface* surface = NULL;
		SDL_Renderer* renderer = NULL;
		SDL_Texture* texture = NULL;

		initialize();
		createWindow(window);
		createSurface(surface);
		CreateRender(renderer, window);
		CreateTexture(texture, renderer, surface);

		SDL_RenderClear(renderer);
		SDL_RenderTexture(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);

		SDL_Delay(5000);

		cleanup(window, surface, renderer, texture);

		return 0;
	}