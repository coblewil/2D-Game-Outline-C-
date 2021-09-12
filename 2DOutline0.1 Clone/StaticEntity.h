#pragma once
#include "Entity.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class Handler;
class StaticEntity : public Entity
{
private:
protected:
//Protected Variables
	SDL_Rect posRenderRect;
public:
//Constructors/Destructors
	StaticEntity(const std::shared_ptr<Handler>& handler, float x, float y, int width, int height);
	~StaticEntity();

//Public Functions
	virtual void tick() = 0;
	virtual void render(const std::shared_ptr<SDL_Renderer>& gRenderer) = 0;
};

