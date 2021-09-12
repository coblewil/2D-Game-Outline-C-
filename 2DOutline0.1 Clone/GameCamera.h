#pragma once
#include "Entity.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class Handler;
class GameCamera
{
private:
//Private Variables
	std::shared_ptr<Handler> handler;
	float xOffset, yOffset;

public:
//Constructor/Destructors
	GameCamera(const std::shared_ptr<Handler>& handler, float xOffset, float yOffset);

//Public Functions
	void checkBlankSpace();
	void centerOnEntity(const std::shared_ptr<Entity>& e);
	void move(float xAmt, float yAmt);

	float getXOffset() const;
	float getYOffset() const;
};

