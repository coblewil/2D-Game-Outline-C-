#include "EntityManager.h"
#include "Entity.h"
#include <algorithm>

EntityManager::EntityManager(const std::shared_ptr<Handler>& handler, std::shared_ptr<Player> player):
	handler{handler},
	player{player},
	entities{}
{
	addEntity(player);
}

EntityManager::~EntityManager()
{
}

bool EntityManager::compare(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b) {
	return a->getY() + a->getHeight() < b->getY() + b->getHeight();
}

void EntityManager::addEntity(std::shared_ptr<Entity> e)
{
	entities.push_back(e);
}

void EntityManager::tick()
{
	for (std::shared_ptr<Entity> e : entities) {
		e->tick();
	}
	std::sort(entities.begin(), entities.end(), &compare);
}

void EntityManager::render(const std::shared_ptr<SDL_Renderer>& gRenderer)
{
	for (std::shared_ptr<Entity> e : entities) {
		e->render(gRenderer);
	}
}

std::vector<std::shared_ptr<Entity>> EntityManager::getEntities() const
{
	return entities;
}

std::shared_ptr<Player> EntityManager::getPlayer() const
{
	return player;
}

std::shared_ptr<Handler> EntityManager::getHandler() const
{
	return handler;
}
