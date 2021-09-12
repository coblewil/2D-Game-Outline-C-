#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class UIObject
{
private:
protected:
//Protected Variables
	float x, y;
	int width, height;
	SDL_Rect posRect;
	SDL_Rect bounds;
	bool hovering;
public:
//Constructors/Destructors
	UIObject(float x, float y, int width, int height);

//Public Functions
	virtual void tick() = 0;
	virtual void render(const std::shared_ptr<SDL_Renderer>& gRenderer) = 0;
	virtual void onClick() = 0;
	virtual void onMouseMove(SDL_Event* e);
	virtual void onMouseRelease(SDL_Event* e);
};

