#include "Creature.h"
#include "Entity.h"
#include "SubTexture.h"
#include "Handler.h"

const int Creature::DEFAULT_HEALTH{ 10 };
const float Creature::DEFAULT_VEL{ 3.0f };
const int Creature::DEFAULT_CREATURE_WIDTH{ 64 };
const int Creature::DEFAULT_CREATURE_HEIGHT{ 64 };

Creature::Creature(const std::shared_ptr<Handler>& handler, float x, float y, int width, int height) :
	Entity(handler, x,y,width,height),
	health{DEFAULT_HEALTH},
	vel{DEFAULT_VEL},
	posRenderRect{}
{
	posRenderRect.x = static_cast<int>(x);
	posRenderRect.y = static_cast<int>(y);
	posRenderRect.w = width;
	posRenderRect.h = height;
	xMove = 0;
	yMove = 0;
}

Creature::~Creature()
{
}

void Creature::move()
{
	if (!checkEntityCollisions(xMove, 0)) {
		moveX();
	}
	if (!checkEntityCollisions(0, yMove)) {
		moveY();
	}
}

void Creature::moveX()
{
	if (xMove > 0) {//Moving right
		int tx = static_cast<int>(x+xMove+bounds->x+bounds->w)/Tile::TILE_WIDTH;
		if (!collisionWithTile(tx, static_cast<int>(y + bounds->y)/Tile::TILE_HEIGHT) && !collisionWithTile(tx, static_cast<int>(y + bounds->y + bounds->h) / Tile::TILE_HEIGHT)) {
			x += xMove;
		}
		else {
			x = tx * Tile::TILE_WIDTH - bounds->x - bounds->w-1;
		}
	}
	else if (xMove < 0) {//Moving left
		int tx = static_cast<int>(x + xMove + bounds->x) / Tile::TILE_WIDTH;
		if (!collisionWithTile(tx, static_cast<int>(y + bounds->y) / Tile::TILE_HEIGHT) && !collisionWithTile(tx, static_cast<int>(y + bounds->y + bounds->h) / Tile::TILE_HEIGHT)) {
			x += xMove;
		}
		else {
			x = tx * Tile::TILE_WIDTH + Tile::TILE_WIDTH - bounds->x;
		}
	}
}

void Creature::moveY()
{
	if (yMove < 0) {//Moving up
		int ty = static_cast<int>(y + yMove + bounds->y) / Tile::TILE_HEIGHT;
		if (!collisionWithTile(static_cast<int>(x + bounds->x) / Tile::TILE_WIDTH, ty) && !collisionWithTile(static_cast<int>(x + bounds->x + bounds-> w) / Tile::TILE_WIDTH, ty)) {
			y += yMove;
		}
		else {
			y = ty * Tile::TILE_HEIGHT + Tile::TILE_HEIGHT - bounds->y;
		}
	}
	else if (yMove > 0) {
		int ty = static_cast<int>(y + yMove + bounds->y + bounds->h) / Tile::TILE_HEIGHT;
		if (!collisionWithTile(static_cast<int>(x + bounds->x) / Tile::TILE_WIDTH, ty) && !collisionWithTile(static_cast<int>(x + bounds->x + bounds->w) / Tile::TILE_WIDTH, ty)) {
			y += yMove;
		}
		else {
			y = ty * Tile::TILE_HEIGHT - bounds->y - bounds->h - 1;
		}
	}
}

bool Creature::collisionWithTile(int x, int y)
{
	return handler->getWorld()->getTile(x,y)->isSolid();
}
