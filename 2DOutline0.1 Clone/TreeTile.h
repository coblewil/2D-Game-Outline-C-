#pragma once
#include "Tile.h"
#include "SubTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class TreeTile : public Tile
{
private:
public:
	TreeTile();

	bool isSolid() override;
};
