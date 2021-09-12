#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>
#include "SubTexture.h"
#include "SpriteSheet.h"

class Animation
{
private:
//Private Variables
	Uint32 speed;
	int index;
	Uint32 lastTime, timer;
	std::vector<std::shared_ptr<SubTexture>> frames;
public:
//Constructors/Destructors
	Animation(int speed, std::vector<std::shared_ptr<SubTexture>> frames);
	~Animation();

//Public Functions
	void tick();

//Getters
	std::shared_ptr<SubTexture> getCurrentFrame();
};

