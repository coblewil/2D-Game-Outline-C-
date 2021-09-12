#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(std::shared_ptr<SDL_Texture> sheet):
	sheet{sheet}
{

}

std::shared_ptr<SDL_Rect> SpriteSheet::simpleCrop(int x, int y, int width, int height)
{
	std::shared_ptr<SDL_Rect> r = std::shared_ptr<SDL_Rect>(new SDL_Rect{x,y,width,height});
	return r;
}

std::shared_ptr<SDL_Texture> SpriteSheet::getSheet()
{
	return sheet;
}
