#include "GameState.h"
#include "Tile.h"
#include "Handler.h"

GameState::GameState(const std::shared_ptr<Handler>& handler):
	State{handler}
{
	world = std::make_shared<World>(handler, "res/worlds/world3.txt");
	handler->setWorld(world);
	
}

GameState::~GameState()
{
}

void GameState::tick()
{
	world->tick();
}

void GameState::render(const std::shared_ptr<SDL_Renderer>& gRenderer)
{
	world->render(gRenderer);
	//Tile::getTile(TileID::GrassTile)->render(gRenderer, 200, 0);
	//Tile::getTile(TileID::DirtTile)->render(gRenderer, 250, 50);
	//Tile::getTile(TileID::RockTile)->render(gRenderer, 300, 100);
	SDL_RenderPresent(gRenderer.get());
}
