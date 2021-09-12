#pragma once
#include "UIManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class MouseManager
{
private:
	static bool leftPressed, rightPressed;
	static int mouseX, mouseY;
	static std::shared_ptr<UIManager> uiManager;
public:
//Public Functions
	static void handleEvent(SDL_Event* e);
	static void setUIManager(std::shared_ptr<UIManager> uiManager);

	//Getters
	static int getMouseX();
	static int getMouseY();
	static bool isRightPressed();
	static bool isLeftPressed();
};

