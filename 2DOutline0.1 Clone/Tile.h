#pragma once
#include "SubTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>

enum class TileID {
	GreenTile = 0,
	DirtTile = 1,
	GrassTile = 2,
	TallGrassTile = 3,
	TreeTile = 4
};

class Tile
{
private:
protected:
	//Protected Variables
	std::shared_ptr<SubTexture> texture;
public:
	//Public Variables
	static const int TILE_WIDTH, TILE_HEIGHT;
	static std::vector<std::shared_ptr<Tile>> tiles;

	static std::shared_ptr<Tile> greenTile;
	static std::shared_ptr<Tile> dirtTile;
	static std::shared_ptr<Tile> grassTile;
	static std::shared_ptr<Tile> tallGrassTile;
	static std::shared_ptr<Tile> treeTile;


	const TileID id;
	//Constructors/Destructors
	Tile(std::shared_ptr<SubTexture> texture, TileID id);

	//Public Functions
	static void init();
	static std::shared_ptr<Tile> getTile(TileID t);
	virtual bool isSolid();
	virtual void tick();
	virtual void render(const std::shared_ptr<SDL_Renderer>& gRenderer, int x, int y);
};

