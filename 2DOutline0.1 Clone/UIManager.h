#pragma once
#include "Handler.h"
#include "UIObject.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>

class UIManager
{
private:
//Private Variables
	std::shared_ptr<Handler> handler;
	std::vector<std::shared_ptr<UIObject>> objects;
public:
//Constructor/Destructor
	UIManager(std::shared_ptr<Handler> handler);

//Public Functions
	void onMouseMove(SDL_Event* e);
	void onMouseRelease(SDL_Event* e);
	void addObject(std::shared_ptr<UIObject> o);
	void removeObject(std::shared_ptr<UIObject> o);

	void tick();
	void render(const std::shared_ptr<SDL_Renderer>& gRenderer);
};

