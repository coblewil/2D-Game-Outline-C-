#include "TreeTile.h"
#include "Tile.h"
#include "Assets.h"

TreeTile::TreeTile() :
	Tile{ Assets::tree, TileID::TreeTile }
{
}

bool TreeTile::isSolid()
{
	return true;
}
