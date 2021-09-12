#pragma once
#include "Player.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>

class Handler;
class EntityManager
{
private:
//Private Variables
	std::shared_ptr<Handler> handler;
	std::shared_ptr<Player> player;
	std::vector<std::shared_ptr<Entity>> entities;

//Private Functions
	//Render Comparator Function
	static bool compare(std::shared_ptr<Entity> a, std::shared_ptr<Entity> b);
public:
//Constructors/Destructors
	EntityManager(const std::shared_ptr<Handler>& handler, std::shared_ptr<Player> player);
	~EntityManager();

//Public Functions
	void addEntity(std::shared_ptr<Entity> e);

	void tick();
	void render(const std::shared_ptr<SDL_Renderer>& gRenderer);

	//Getters
	std::vector<std::shared_ptr<Entity>> getEntities() const;
	std::shared_ptr<Player> getPlayer() const;
	std::shared_ptr<Handler> getHandler() const;
};

