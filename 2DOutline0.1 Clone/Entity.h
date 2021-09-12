#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class Handler;
class Entity
{
private:
protected:
//Protected Variables
	std::shared_ptr<Handler> handler;
	float x, y;
	int width, height;
	std::shared_ptr<SDL_Rect> bounds;
public:
//Constructors/Destructors
	Entity(const std::shared_ptr<Handler>& handler, float x, float y, int width, int height);
	~Entity();

//Public Functions
	float getX() const;
	float getY() const;
	int getWidth() const;
	int getHeight() const;

	bool checkEntityCollisions(float x, float y);

	std::shared_ptr<SDL_Rect> getCollisionBounds(float xOffset, float yOffset) const;

	virtual void tick() = 0;
	virtual void render(const std::shared_ptr<SDL_Renderer>& gRenderer) = 0;
};

