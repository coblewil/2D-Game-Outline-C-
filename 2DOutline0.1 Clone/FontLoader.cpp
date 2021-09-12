#include "FontLoader.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <memory>


//WARNING make sure that this works!!!
void font_deleter(TTF_Font* font){
	if (!TTF_WasInit()) {
		return;
	}
	else {
		TTF_CloseFont(font);
	}
}

std::shared_ptr<TTF_Font> FontLoader::loadFont(std::string path, int size)
{
	std::shared_ptr<TTF_Font> gFont = std::shared_ptr<TTF_Font>(TTF_OpenFont(path.c_str(), size), font_deleter);
	if (gFont.get() == NULL) {
		printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
	}

	return gFont;
}
