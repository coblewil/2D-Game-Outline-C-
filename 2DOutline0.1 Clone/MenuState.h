#pragma once
#include "UIManager.h"
#include "State.h"
#include "Assets.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class Handler;
class MenuState : public State
{
private:
	std::shared_ptr<UIManager> uiManager;
public:
	//Constuctors/Destructors
	MenuState(const std::shared_ptr<Handler>& handler);
	~MenuState();

	//Public Functions
	virtual void tick() override;
	virtual void render(const std::shared_ptr<SDL_Renderer>& gRenderer) override;
};

