#pragma once
#include "State.h"
#include "Assets.h"
#include "World.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class Handler;
class GameState : public State
{
private:
//Private variables
	std::shared_ptr<World> world;
public:
//Constuctors/Destructors
	GameState(const std::shared_ptr<Handler>& handler);
	~GameState();

//Public Functions
	virtual void tick() override;
	virtual void render(const std::shared_ptr<SDL_Renderer>& gRenderer) override;
};

