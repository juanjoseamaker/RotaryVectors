#include "vector.hpp"

#include <SDL2/SDL.h>
#include <cmath>

using namespace std;

Vector2::Vector2(float _magnitude, float _angle, float _angularVelocity) {
	magnitude = _magnitude;
	angularVelocity = _angularVelocity;
	angle = _angle;
}

void Vector2::draw(SDL_Renderer *renderer, int& x, int& y, float time, Uint8 r, Uint8 g, Uint8 b) {
	float currentAngle = angle + angularVelocity * time;
	
	float headX = x + magnitude * cos(currentAngle);
	float headY = y + magnitude * sin(currentAngle);
	
	SDL_SetRenderDrawColor(renderer, r, g, b, 0);
	SDL_RenderDrawLine(renderer, x, y, headX, headY);

	x = headX;
	y = headY;
}

