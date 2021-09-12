#include "Tile.h"
#include "Assets.h"
#include "GreenTile.h"
#include "DirtTile.h"
#include "GrassTile.h"
#include "TallGrassTile.h"
#include "TreeTile.h"
#include <memory>
#include <vector>

const int Tile::TILE_WIDTH{ 64 };
const int Tile::TILE_HEIGHT{ 64 };

std::vector<std::shared_ptr<Tile>> Tile::tiles{ 256 };

std::shared_ptr<Tile> Tile::greenTile{ new GreenTile{} };
std::shared_ptr<Tile> Tile::dirtTile{ new DirtTile{} };
std::shared_ptr<Tile> Tile::grassTile{ new GrassTile{} };
std::shared_ptr<Tile> Tile::tallGrassTile{ new TallGrassTile{} };
std::shared_ptr<Tile> Tile::treeTile{ new TreeTile{} };

void Tile::init()
{
	greenTile = std::shared_ptr<Tile>(new GreenTile{});
	dirtTile = std::shared_ptr<Tile>(new DirtTile{});
	grassTile = std::shared_ptr<Tile>(new GrassTile{});
	tallGrassTile = std::shared_ptr<Tile>(new TallGrassTile{});
	treeTile = std::shared_ptr<Tile>(new TreeTile{});

	tiles[static_cast<int>(TileID::GreenTile)] = greenTile;
	tiles[static_cast<int>(TileID::DirtTile)] = dirtTile;
	tiles[static_cast<int>(TileID::GrassTile)] = grassTile;
	tiles[static_cast<int>(TileID::TallGrassTile)] = tallGrassTile;
	tiles[static_cast<int>(TileID::TreeTile)] = treeTile;
}

std::shared_ptr<Tile> Tile::getTile(TileID t)
{
	return tiles[static_cast<int>(t)];
}

bool Tile::isSolid()
{
	return false;
}

Tile::Tile(std::shared_ptr<SubTexture> texture, TileID id):
	texture{texture},
	id{id}
{
}

void Tile::tick()
{
}

void Tile::render(const std::shared_ptr<SDL_Renderer>& gRenderer, int x, int y)
{
	SDL_Rect r{ x,y,TILE_WIDTH, TILE_HEIGHT };
	SDL_RenderCopy(gRenderer.get(), texture->getTexturePtr(), texture->getSubTextureRectPtr(), &r);
}
