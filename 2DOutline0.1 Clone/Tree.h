#pragma once
#include "StaticEntity.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class Tree : public StaticEntity
{
private:
	SDL_Rect boundsRenderRect;
public:
//Constructors/Destructors
	Tree(const std::shared_ptr<Handler>& handler, float x, float y);
	~Tree();

//Public Functions
	virtual void tick();
	virtual void render(const std::shared_ptr<SDL_Renderer>& gRenderer);
};

