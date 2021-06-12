#ifndef VECTOR_H
#define VECTOR_H

#include <SDL2/SDL.h>

class Vector2 {
    private:
        float magnitude;
        float angle;

    public:
        Vector2(float mg, float a);
        void draw(SDL_Renderer *renderer, int x, int y, Uint8 r, Uint8 g, Uint8 b);
};

#endif