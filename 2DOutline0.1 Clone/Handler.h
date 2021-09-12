#pragma once
#include "World.h"
#include "GameCamera.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>


class Game;
class Handler
{
private:
//Private Variables
	std::weak_ptr<Game> game;
	std::shared_ptr<World> world;
public:
//Constructor/Destructor
	Handler(const std::shared_ptr<Game>& game);
	~Handler();

//Public Functions

	//Getters
	int getWidth() const;
	int getHeight() const;
	std::shared_ptr<GameCamera> getGameCamera() const;
	std::shared_ptr<World> getWorld() const;
	std::weak_ptr<Game> getGame() const;

	//Setters
	void setWorld(std::shared_ptr<World> world);
};

