#include "Handler.h"
#include "Game.h"
#include "GameCamera.h"
#include "World.h"

Handler::Handler(const std::shared_ptr<Game>& game):
	game{game}
{
}

Handler::~Handler()
{
}

int Handler::getWidth() const
{
	return game.lock()->getWidth();
}

int Handler::getHeight() const
{
	return game.lock()->getHeight();
}

std::shared_ptr<GameCamera> Handler::getGameCamera() const
{
	return game.lock()->getGameCamera();
}

std::shared_ptr<World> Handler::getWorld() const
{
	return world;
}

std::weak_ptr<Game> Handler::getGame() const
{
	return game;
}

void Handler::setWorld(std::shared_ptr<World> world)
{
	this->world = world;
}
