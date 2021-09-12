#include "World.h"
#include "Handler.h"
#include "Utils.h"
#include "EntityManager.h"
#include "Player.h"
#include "Tree.h"
#include "Rock.h"
#include "Assets.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include <algorithm>

World::World(const std::shared_ptr<Handler>& handler, std::string path):
	handler{handler},
	entityManager{ new EntityManager{handler, Player::create(handler, 100, 100)} }
{
	entityManager->addEntity(std::make_shared<Tree>(handler, Tile::TILE_WIDTH * 3, Tile::TILE_HEIGHT * 5));
	entityManager->addEntity(std::make_shared<Tree>(handler, Tile::TILE_WIDTH * 10 + 12, Tile::TILE_HEIGHT * 10 - 14));
	entityManager->addEntity(std::make_shared<Tree>(handler, Tile::TILE_WIDTH * 13 + 12, Tile::TILE_HEIGHT * 15 - 14));
	entityManager->addEntity(std::make_shared<Tree>(handler, Tile::TILE_WIDTH * 14 + 12, Tile::TILE_HEIGHT * 15 - 14));
	entityManager->addEntity(std::make_shared<Tree>(handler, Tile::TILE_WIDTH * 15 + 12, Tile::TILE_HEIGHT * 15 - 14));
	entityManager->addEntity(std::make_shared<Rock>(handler, 100, 300));

	entityManager->addEntity(std::make_shared<Rock>(handler, 100, 500));
	entityManager->addEntity(std::make_shared<Rock>(handler, 132, 500));
	entityManager->addEntity(std::make_shared<Rock>(handler, 164, 500));
	entityManager->addEntity(std::make_shared<Rock>(handler, 100, 532));
	entityManager->addEntity(std::make_shared<Rock>(handler, 132, 532));
	entityManager->addEntity(std::make_shared<Rock>(handler, 164, 532));
	entityManager->addEntity(std::make_shared<Rock>(handler, 100, 564));
	entityManager->addEntity(std::make_shared<Rock>(handler, 132, 564));
	entityManager->addEntity(std::make_shared<Rock>(handler, 164, 564));

	loadWorld(path);

	entityManager->getPlayer()->setX(spawnX);
	entityManager->getPlayer()->setY(spawnY);
}

void World::loadWorld(std::string path)
{
	std::string file = Utils::loadFileAsString(path);
	std::regex re = std::regex("\\s+");
	std::vector<std::string> tokens = tokenizer(file, re);
	colCount = Utils::parseInt(tokens[0]);
	rowCount = Utils::parseInt(tokens[1]);
	spawnX = Utils::parseInt(tokens[2]);
	spawnY = Utils::parseInt(tokens[3]);

	worldTiles = std::vector<std::vector<TileID>>( colCount, std::vector<TileID>(rowCount) );
	for (int y = 0; y < rowCount; y++) {
		for (int x = 0; x < colCount; x++) {
			worldTiles[x][y] = static_cast<TileID>(Utils::parseInt(tokens[(x + y * colCount) + 4]));
		}
	}
}

std::shared_ptr<EntityManager> World::getEntityManager() const
{
	return entityManager;
}

std::shared_ptr<Tile> World::getTile(int x, int y)
{
	if (x < 0 || y < 0 || x >= colCount || y >= rowCount) {
		return Tile::greenTile;
	}
	std::shared_ptr<Tile> t = Tile::getTile(worldTiles[x][y]);
	if (t.get() == nullptr) {
		return Tile::dirtTile;
	}
	return t;
}

int World::getWidth() const
{
	return colCount;
}

int World::getHeight() const
{
	return rowCount;
}

void World::tick()
{
	entityManager->tick();
}

void World::render(const std::shared_ptr<SDL_Renderer>& gRenderer)
{
	xStart = std::max(0, static_cast<int>(handler->getGameCamera()->getXOffset() / Tile::TILE_WIDTH));
	xEnd = std::min(colCount, static_cast<int>((handler->getGameCamera()->getXOffset()+handler->getWidth())/Tile::TILE_WIDTH + 1));
	yStart = std::max(0, static_cast<int>(handler->getGameCamera()->getYOffset() / Tile::TILE_HEIGHT));
	yEnd = std::min(rowCount, static_cast<int>((handler->getGameCamera()->getYOffset() + handler->getHeight()) / Tile::TILE_HEIGHT + 1));

	for (int y = yStart; y < yEnd; y++) {
		for (int x = xStart; x < xEnd; x++) {
			SDL_Rect r{ static_cast<int>(x * Tile::TILE_WIDTH - handler->getGameCamera()->getXOffset()), static_cast<int>(y * Tile::TILE_HEIGHT - handler->getGameCamera()->getYOffset()), 64, 64};
			SDL_RenderCopy(gRenderer.get(), Assets::green->getTexturePtr(), Assets::green->getSubTextureRectPtr(), &r); //First rendering a green tile under every tile as a hack around partially transparent tiles
			getTile(x, y)->render(gRenderer, static_cast<int>(x* Tile::TILE_WIDTH - handler->getGameCamera()->getXOffset()), static_cast<int>(y*Tile::TILE_HEIGHT - handler->getGameCamera()->getYOffset()));
		}
	}

	entityManager->render(gRenderer);
}

std::vector<std::string> World::tokenizer(const std::string& str, const std::regex re) {
	std::sregex_token_iterator it{ str.begin(), str.end(), re, -1 };
	std::vector<std::string> tokenized{ it, {} };

	tokenized.erase(std::remove_if(tokenized.begin(), tokenized.end(), [](std::string const& s) {return s.size() == 0; }), tokenized.end());

	return tokenized;
}
