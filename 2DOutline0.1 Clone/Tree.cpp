#include "Tree.h"
#include "Tile.h"
#include "Assets.h"
#include "Handler.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

Tree::Tree(const std::shared_ptr<Handler>& handler, float x, float y):
	StaticEntity{handler, x, y, Assets::tree->getInherentSubTextureWidth(), Assets::tree->getInherentSubTextureHeight()}
{
	bounds->x = 0;
	bounds->y = 40;
	bounds->w = Assets::tree->getInherentSubTextureWidth();
	bounds->h = Assets::tree->getInherentSubTextureHeight();
}

Tree::~Tree()
{
}

void Tree::tick()
{
}

void Tree::render(const std::shared_ptr<SDL_Renderer>& gRenderer)
{
	//SDL_SetRenderDrawColor(gRenderer.get(), 0, 0, 255, 255);
	posRenderRect.x = static_cast<int>(x - handler->getGameCamera()->getXOffset());
	posRenderRect.y = static_cast<int>(y - handler->getGameCamera()->getYOffset());
	SDL_RenderCopy(gRenderer.get(), Assets::tree->getTexturePtr(), Assets::tree->getSubTextureRectPtr(), &posRenderRect);
	/*boundsRenderRect.x = x + bounds->x - handler->getGameCamera()->getXOffset();
	boundsRenderRect.y = y + bounds->y - handler->getGameCamera()->getYOffset();
	boundsRenderRect.w = bounds->w;
	boundsRenderRect.h = bounds->h;
	SDL_RenderFillRect(gRenderer.get(), &boundsRenderRect);*/
}
