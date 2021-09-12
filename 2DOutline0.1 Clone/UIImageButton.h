#pragma once
#include "UIObject.h"
#include "SubTexture.h"
#include "ClickListener.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>

class UIImageButton : public UIObject
{
private:
//Private Variables
	std::vector<std::shared_ptr<SubTexture>> images;
	std::shared_ptr<ClickListener> clicker;

public:
//Constructor/Destructor
	UIImageButton(float x, float y, int width, int height, std::vector<std::shared_ptr<SubTexture>> images, std::shared_ptr<ClickListener> clicker);

//Public Functions
	virtual void tick();
	virtual void render(const std::shared_ptr<SDL_Renderer>& gRenderer);
	virtual void onClick();
	//virtual void onMouseMove(SDL_Event* e);
	//virtual void onMouseRelease(SDL_Event* e);
};

