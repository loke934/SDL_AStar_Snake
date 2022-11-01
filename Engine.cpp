#include "Engine.h"

SDL_Window* window;
SDL_Renderer* render;
float deltaTime = 0.f;

Uint64 previousTicks = SDL_GetPerformanceCounter();
Uint64 ticks = 0.f;
Uint64 deltaTicks = 0.f;


void Engine::SetDeltaTime()
{
    ticks = SDL_GetPerformanceCounter();
    deltaTicks = ticks-previousTicks;
    previousTicks = ticks;
    deltaTime = (float)deltaTicks / SDL_GetPerformanceFrequency();
}
