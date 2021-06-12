#include "vector.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

using namespace std;

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600

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

    Vector2 mainVector1(50, 0, 2 * M_PI);
    Vector2 mainVector2(50, 0, M_PI);
    float time = 0;

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

		// Loop
		int x = SCREEN_WIDTH/2, y = SCREEN_HEIGHT/2;
		mainVector1.draw(renderer, x, y, time, 255, 0, 0);
		mainVector2.draw(renderer, x, y, time, 255, 0, 0);
		time += 0.05;
		
        SDL_RenderPresent(renderer);
        
        SDL_Delay(50);
    }
}
