#include "SubTexture.h"

SubTexture::SubTexture(std::shared_ptr<SDL_Texture> texture, int x, int y, int width, int height):
	texture{texture},
	subTextureRect{ std::shared_ptr<SDL_Rect>(new SDL_Rect{x,y,width,height}) },
	INHERENT_SUBTEXTURE_WIDTH{width},
	INHERENT_SUBTEXTURE_HEIGHT{height}
{
}

SubTexture::~SubTexture()
{
}

SDL_Texture* SubTexture::getTexturePtr()
{
	return texture.get();
}

std::shared_ptr<SDL_Texture> SubTexture::getTexture()
{
	return texture;
}

SDL_Rect* SubTexture::getSubTextureRectPtr()
{
	return subTextureRect.get();
}

std::shared_ptr<SDL_Rect> SubTexture::getSubTextureRect()
{
	return subTextureRect;
}

const int SubTexture::getInherentSubTextureWidth() const
{
	return INHERENT_SUBTEXTURE_WIDTH;
}

const int SubTexture::getInherentSubTextureHeight() const
{
	return INHERENT_SUBTEXTURE_HEIGHT;
}
