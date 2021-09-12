#pragma once
#include "Tile.h"
#include "EntityManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>
#include <regex>

class Handler;
class World
{
private:
//Private Variables
	std::shared_ptr<Handler> handler;
	int rowCount, colCount;
	int spawnX, spawnY;
	std::vector<std::vector<TileID>> worldTiles;

	std::shared_ptr<EntityManager> entityManager;

	int xStart{};
	int xEnd{};
	int yStart{};
	int yEnd{};

//Private Functions
	void loadWorld(std::string path);

public:
//Constructors/Destructors
	World(const std::shared_ptr<Handler>& handler, std::string path);

//Public Functions
	//Getters
	std::shared_ptr<EntityManager> getEntityManager() const;
	std::shared_ptr<Tile> getTile(int x, int y);
	int getWidth() const;
	int getHeight() const;
	
	void tick();
	void render(const std::shared_ptr<SDL_Renderer>& gRenderer);
	std::vector<std::string> tokenizer(const std::string& str, const std::regex re);
};

