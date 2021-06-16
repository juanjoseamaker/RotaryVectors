#include "vector.hpp"
#include "vector_chain.hpp"

#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#include <cstdint>

using namespace std;

static uint8_t pathBuffer[SCREEN_HEIGHT][SCREEN_WIDTH] = {{0}};

void copyPathBuffer(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 0);
	for(int y = 0; y < SCREEN_HEIGHT; y++) {
		for(int x = 0; x < SCREEN_WIDTH; x++) {
			if(pathBuffer[y][x])
				SDL_RenderDrawPoint(renderer, x, y);
		}
	}
}

int main() {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        cout << "Failed to initialize the SDL2 library" << endl;
        cout << "SDL2 Error: " << SDL_GetError() << endl;
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Rotatory Vectors",
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

    VectorChain vectorChain(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

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
				case SDLK_UP:    vectorChain.changeMagnitude(5);		break;
				case SDLK_DOWN:  vectorChain.changeMagnitude(-5);		break;
				case SDLK_LEFT:  vectorChain.changeDirection(-M_PI/10); break;
				case SDLK_RIGHT: vectorChain.changeDirection(M_PI/10);	break;
				case SDLK_SPACE: vectorChain.selectNext();				break;
				case SDLK_c: 	 vectorChain.addVector();				break;
				}
				break;
			}
        }

		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
		SDL_RenderClear(renderer);

		// Loop
		vectorChain.update(renderer, 0.01, pathBuffer);

		copyPathBuffer(renderer);
        SDL_RenderPresent(renderer);
        
        SDL_Delay(10);
    }
}
