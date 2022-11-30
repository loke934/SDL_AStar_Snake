#pragma once
#include <SDL/SDL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

extern SDL_Window* window;
extern SDL_Renderer* render;
extern float deltaTime;

class Engine
{
public:
    static void SetDeltaTime();
};
