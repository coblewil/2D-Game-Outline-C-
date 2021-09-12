#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class SpriteSheet
{
private:
	//Private Variables
	std::shared_ptr<SDL_Texture> sheet;

public:
	//Constructors/Destructors
	SpriteSheet(std::shared_ptr<SDL_Texture> sheet);
	SpriteSheet() = delete;

	//Public Functions
	std::shared_ptr<SDL_Rect> simpleCrop(int x, int y, int width, int height);
	std::shared_ptr<SDL_Texture> getSheet();
};

