#ifndef VECTOR_CHAIN_H
#define VECTOR_CHAIN_H

#include <vector>
#include <SDL2/SDL.h>
#include <cstdint>

#include "vector.hpp"

class VectorChain {
	private:
		std::vector<Vector2> vectorChain;
		int posX, posY;
		size_t selected;
		float time;
		bool running;

	public:
		VectorChain(int x, int y);
		
		void update(SDL_Renderer *renderer, float frameTime, uint8_t pathBuffer[SCREEN_HEIGHT][SCREEN_WIDTH]);
		
		void selectNext();
		void addVector();
		
		void changeDirection(float dir);
		void changeMagnitude(float magnitude);
};

#endif
