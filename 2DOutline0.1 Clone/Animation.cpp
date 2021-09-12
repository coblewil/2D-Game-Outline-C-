#include "Animation.h"
#include <chrono>

Animation::Animation(int speed, std::vector<std::shared_ptr<SubTexture>> frames):
	speed{static_cast<Uint32>(speed)},
	frames{frames},
	index{0},
	timer{ static_cast < Uint32>(0)},
	lastTime{SDL_GetTicks()}
{
}

Animation::~Animation()
{
}

void Animation::tick()
{
	timer += SDL_GetTicks() - lastTime;
	lastTime = SDL_GetTicks();

	if (timer > speed) {
		index++;
		timer = 0;
		if (index >= frames.size()) {
			index = 0;
		}
	}
}

std::shared_ptr<SubTexture> Animation::getCurrentFrame()
{
	return frames[index];
}
