#include <vector>
#include <SDL2/SDL.h>
#include <cstdint>
#include <cmath>

#include "vector.hpp"
#include "vector_chain.hpp"

using namespace std;

#define DEFAULT_VECTOR_MAGNITUDE 100

VectorChain::VectorChain(int x, int y) {
	posX = x;
	posY = y;

	selected = 0;

	time = 0;
	running = false;

	addVector();
}

void VectorChain::startRunning() {
	running = true;
}

void VectorChain::stopRunning(uint8_t pathBuffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	running = false;
	time = 0;

	for(int y = 0; y < SCREEN_HEIGHT; y++) {
		for(int x = 0; x < SCREEN_WIDTH; x++) {
			pathBuffer[y][x] = 0;
		}
	}
}

void VectorChain::update(SDL_Renderer *renderer, float frameTime, uint8_t pathBuffer[SCREEN_HEIGHT][SCREEN_WIDTH]) {
	if(running) {
		time += frameTime;

		int x = posX, y = posY;

		for(auto &vector : vectorChain) {
			vector.draw(renderer, x, y, time, 0, 255, 0);
		}

		if(y > 0 && y < SCREEN_HEIGHT && x > 0 && x < SCREEN_WIDTH)
			pathBuffer[y][x] = 1;
	} else {
		int x = posX, y = posY;

		for(size_t i = 0; i < vectorChain.size(); i++) {
			if(selected == i) {
				vectorChain[i].draw(renderer, x, y, 0, 255, 0, 0);
			} else {
				vectorChain[i].draw(renderer, x, y, 0, 0, 255, 0);
			}
		}
	} 
}

void VectorChain::selectNext() {
	selected++;
	if(selected >= vectorChain.size()) selected = 0;
}

void VectorChain::addVector() {
	vectorChain.push_back(Vector2(DEFAULT_VECTOR_MAGNITUDE, 0, M_PI));
}

void VectorChain::removeVector() {
	if(vectorChain.size() > 1) vectorChain.pop_back();
	if(selected >= vectorChain.size()) selected = vectorChain.size() - 1;
}

void VectorChain::changeDirection(float dir) {
	vectorChain[selected].angle += dir;
}

void VectorChain::changeAngularVelocity(float vel) {
	vectorChain[selected].angularVelocity += vel;
}

void VectorChain::changeMagnitude(float magnitude) {
	vectorChain[selected].magnitude += magnitude;
}
