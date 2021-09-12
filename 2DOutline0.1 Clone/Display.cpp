#include "Display.h"
#include <memory>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

void Display::createDisplay()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else {
		gWindow = std::shared_ptr<SDL_Window>(SDL_CreateWindow(TITLE.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN), SDL_DestroyWindow);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else {
			gRenderer = std::shared_ptr<SDL_Renderer>(SDL_CreateRenderer(gWindow.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), SDL_DestroyRenderer);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			}
			else
			{
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
				}

				//Initialize SD_ttf
				if (TTF_Init() == -1) {
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", SDL_GetError());//visual studio says TTF_GetError() is undefined???
				}
			}
		}
	}
}

Display::Display(std::string title, int width, int height):
	TITLE{title},
	SCREEN_WIDTH{width},
	SCREEN_HEIGHT{height},
	gWindow{nullptr, SDL_DestroyWindow},
	gRenderer{nullptr, SDL_DestroyRenderer}
{
	createDisplay();
}

Display::~Display()
{
	//gRenderer = nullptr;
	//gWindow = nullptr;
}

std::shared_ptr<SDL_Renderer> Display::getRenderer()
{
	return gRenderer;
}
