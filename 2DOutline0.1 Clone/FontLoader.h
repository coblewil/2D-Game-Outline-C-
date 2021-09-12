#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <memory>

class FontLoader
{
public:
	static std::shared_ptr<TTF_Font> loadFont(std::string path, int size);
};

