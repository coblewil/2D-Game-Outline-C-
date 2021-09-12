#include "UIObject.h"
#include "MouseManager.h"

UIObject::UIObject(float x, float y, int width, int height):
	x{x},
	y{y},
	width{width},
	height{height},
	bounds{static_cast<int>(x), static_cast<int>(y), width, height},
	hovering{false},
	posRect{static_cast<int>(x), static_cast<int>(y),width,height}
{
}

void UIObject::onMouseMove(SDL_Event* e)
{
	SDL_Point p{ MouseManager::getMouseX(), MouseManager::getMouseY() };
	if (SDL_PointInRect( &p, &bounds)) {
		hovering = true;
	}
	else {
		hovering = false;
	}
}

void UIObject::onMouseRelease(SDL_Event* e)
{
	if (hovering) {
		onClick();
	}
}
