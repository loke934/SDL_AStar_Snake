#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "Engine.h"
#include "Game.h"
#include <ctime>


int main(int argc, char** argv)
{
	srand( time(NULL));
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("SDL AStar Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,0);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(render, 20, 0, 0, 255);
	SDL_RenderClear(render);
	
	bool isRunning = true;
	Game game;
	Engine engine;
	game.SetupGame();
	
	while (isRunning)
	{
		engine.SetDeltaTime();
		
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				isRunning = false;
				game.EndGame();
				break;
				
			case SDL_KEYDOWN:
				int scancode = event.key.keysym.scancode;
				if (scancode == SDL_SCANCODE_ESCAPE)
				{
					isRunning = false;
					game.EndGame();
					break;
				}
			}
		}
		game.UpdateGame();
		SDL_RenderPresent(render);
	}
	return 0;
}
