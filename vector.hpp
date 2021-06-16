#ifndef VECTOR_H
#define VECTOR_H

#include <SDL2/SDL.h>

#define SCREEN_WIDTH  600
#define SCREEN_HEIGHT 600

class Vector2 {
    public:
        float magnitude;
        float angle;
        float angularVelocity;

        Vector2(float _magnitude, float _angle, float _angularVelocity);
        void draw(SDL_Renderer *renderer, int &x, int &y, float time, Uint8 r, Uint8 g, Uint8 b);
};

#endif
