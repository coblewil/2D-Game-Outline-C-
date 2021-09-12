#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class ImageLoader
{
private:
public:
	static std::shared_ptr<SDL_Texture> loadImage(const std::shared_ptr<SDL_Renderer>& gRenderer, std::string path);
};

