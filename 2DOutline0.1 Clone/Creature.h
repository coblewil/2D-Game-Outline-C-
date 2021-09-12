#pragma once
#include "Entity.h"
#include "SubTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class Handler;
class Creature : public Entity
{
private:
protected:
	//Protected Variables
	std::shared_ptr<SubTexture> texture;
	SDL_Rect posRenderRect;
	int health;
	float vel;
	float xMove, yMove;

	//Protected Functions
	void move();
	void moveX();
	void moveY();

	bool collisionWithTile(int x, int y);
public:
	//Constructors/Destructors
	Creature(const std::shared_ptr<Handler>& handler, float x, float y, int width = DEFAULT_CREATURE_WIDTH, int height = DEFAULT_CREATURE_HEIGHT);
	~Creature();

	//Public Variables
	static const int DEFAULT_HEALTH;
	static const float DEFAULT_VEL;
	static const int DEFAULT_CREATURE_WIDTH,
					 DEFAULT_CREATURE_HEIGHT;

	//Public Functions
	virtual void tick() override = 0;
	virtual void render(const std::shared_ptr<SDL_Renderer>& gRenderer) override = 0;
};

