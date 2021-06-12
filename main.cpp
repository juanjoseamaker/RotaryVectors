#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 800

int main() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "Failed to initialize the SDL2 library" << endl;
        cout << "SDL2 Error: " << SDL_GetError() << endl;
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Ray Casting",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH,
                                          SCREEN_HEIGHT,
                                          0);

    if(!window) {
        cout << "Failed to create window" << endl;
        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(!renderer) {
        cout << "Failed to get the renderer from the window" << endl;
        cout << "SDL2 Error: " << SDL_GetError() << endl;
        return -1;
    }

    bool running = true;
    
    while(running) {
        SDL_Event e;
        
        while(SDL_PollEvent(&e) > 0) {
			switch(e.type) {
			case SDL_QUIT:
				running = false;
			    break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_UP:    break;
				case SDLK_DOWN:  break;
				case SDLK_LEFT:  break;
				case SDLK_RIGHT: break;
				}
				break;
			}
        }

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_RenderClear(renderer);

		// Game Loop
		
        SDL_RenderPresent(renderer);
        
        SDL_Delay(50);
    }
}
