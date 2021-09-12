#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include "SpriteSheet.h"

class SubTexture
{
private:
	std::shared_ptr<SDL_Texture> texture;
	std::shared_ptr<SDL_Rect> subTextureRect;

	const int INHERENT_SUBTEXTURE_HEIGHT;
	const int INHERENT_SUBTEXTURE_WIDTH;
public:
	//Constructors/Destructors
	SubTexture(std::shared_ptr<SDL_Texture> texture, int x, int y, int width, int height);
	~SubTexture();

	//Public Functions
	SDL_Texture* getTexturePtr();
	std::shared_ptr<SDL_Texture> getTexture();
	SDL_Rect* getSubTextureRectPtr();
	std::shared_ptr<SDL_Rect> getSubTextureRect();

	const int getInherentSubTextureWidth() const;
	const int getInherentSubTextureHeight() const;
};

