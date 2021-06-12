#ifndef VECTOR_H
#define VECTOR_H

#include <SDL2/SDL.h>

class Vector2 {
    private:
        float magnitude;
        float angle;
        float angularVelocity;

    public:
        Vector2(float _magnitude, float _angle, float _angularVelocity);
        void draw(SDL_Renderer *renderer, int &x, int &y, float time, Uint8 r, Uint8 g, Uint8 b);
};

#endif
