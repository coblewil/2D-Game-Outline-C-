#include "GameCamera.h"
#include "Handler.h"
#include "Entity.h"

GameCamera::GameCamera(const std::shared_ptr<Handler>& handler, float xOffset, float yOffset):
	handler{handler},
	xOffset{ xOffset },
	yOffset{ yOffset }
{
}

void GameCamera::checkBlankSpace()
{
	if (xOffset < 0) {
		xOffset = 0;
	}
	else if (xOffset > handler->getWorld()->getWidth() * Tile::TILE_WIDTH - handler->getWidth()) {
		xOffset = handler->getWorld()->getWidth() * Tile::TILE_WIDTH - handler->getWidth();
	}

	if (yOffset < 0) {
		yOffset = 0;
	}
	else if (yOffset > handler->getWorld()->getHeight() * Tile::TILE_HEIGHT - handler->getHeight()) {
		yOffset = handler->getWorld()->getHeight() * Tile::TILE_HEIGHT - handler->getHeight();
	}
}

void GameCamera::centerOnEntity(const std::shared_ptr<Entity>& e)
{
	xOffset = e->getX() - handler->getWidth()/2 + e->getWidth() / 2;
	yOffset = e->getY() - handler->getHeight()/2 + e->getHeight() / 2;
	checkBlankSpace();
}

void GameCamera::move(float xAmt, float yAmt)
{
	xOffset += xAmt;
	yOffset += yAmt;
	checkBlankSpace();
}

float GameCamera::getXOffset() const
{
	return xOffset;
}

float GameCamera::getYOffset() const
{
	return yOffset;
}
