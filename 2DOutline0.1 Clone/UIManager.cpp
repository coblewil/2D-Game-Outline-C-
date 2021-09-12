#include "UIManager.h"
#include <algorithm>

UIManager::UIManager(std::shared_ptr<Handler> handler):
	handler{handler},
	objects{}
{
}

void UIManager::onMouseMove(SDL_Event* e)
{
	for (const std::shared_ptr<UIObject>& o : objects) {
		o->onMouseMove(e);
	}
}

void UIManager::onMouseRelease(SDL_Event* e)
{
	for (const std::shared_ptr<UIObject>& o : objects) {
		o->onMouseRelease(e);
	}
}

void UIManager::addObject(std::shared_ptr<UIObject> o)
{
	objects.push_back(o);
}

void UIManager::removeObject(std::shared_ptr<UIObject> o)
{
	objects.erase(std::remove(objects.begin(), objects.end(), o), objects.end());
}

void UIManager::tick()
{
	for (const std::shared_ptr<UIObject>& o : objects) {
		o->tick();
	}
}

void UIManager::render(const std::shared_ptr<SDL_Renderer>& gRenderer)
{
	for (const std::shared_ptr<UIObject>& o : objects) {
		o->render(gRenderer);
	}
}
