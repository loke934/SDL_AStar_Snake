#include <stdio.h>
#include <SDL/SDL.h>
#include <stdlib.h>
#include "Engine.h"
#include "Game.h"
#include <ctime>
#include <SDL/SDL_ttf.h>

int main(int argc, char** argv)
{
	srand( time(NULL));
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("SDL AStar Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,0);
	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(render, 20, 0, 0, 255);
	SDL_RenderClear(render);

	TTF_Init();
	TTF_Font* font = TTF_OpenFont("res/roboto.ttf", 50);
	SDL_Surface* text_surf = TTF_RenderText_Solid(font, "Game Over!", {255, 0, 0, 255} );
	SDL_Texture* text_texture =SDL_CreateTextureFromSurface(render, text_surf);
	
	bool isRunning = true;
	bool isGameOver = false;
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
				break;
				
			case SDL_KEYDOWN:
				int scancode = event.key.keysym.scancode;
				if (scancode == SDL_SCANCODE_ESCAPE)
				{
					isRunning = false;
					break;
				}
			}
		}
		isGameOver =  game.UpdateGame();
		if (isGameOver)
		{
			SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
			SDL_RenderClear(render);
			SDL_Rect text_dst = { (WINDOW_WIDTH /2) - (text_surf->w /2), (WINDOW_HEIGHT/2) -text_surf->h , text_surf->w, text_surf->h };
			SDL_RenderCopy(render, text_texture, NULL, &text_dst);
		}
		SDL_RenderPresent(render);
	}
	return 0;
}
