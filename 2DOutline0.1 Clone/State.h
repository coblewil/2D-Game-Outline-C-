#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class Handler;
class State
{
private:
public:
	//Constructors/Destructors
	State(const std::shared_ptr<Handler>& handler);
	~State();

	//Public Variables
	std::shared_ptr<Handler> handler;

	//Public Functions
	virtual void tick() = 0;
	virtual void render(const std::shared_ptr<SDL_Renderer>& gRenderer) = 0;
};

