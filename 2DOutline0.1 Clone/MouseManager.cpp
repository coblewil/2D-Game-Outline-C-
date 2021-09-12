#include "MouseManager.h"

bool MouseManager::leftPressed{ false };
bool MouseManager::rightPressed{ false };
int MouseManager::mouseX{};
int MouseManager::mouseY{};
std::shared_ptr<UIManager> MouseManager::uiManager{nullptr};

void MouseManager::handleEvent(SDL_Event* e)
{
	if (e->type == SDL_MOUSEMOTION) {
		SDL_GetMouseState(&mouseX, &mouseY);
		if (uiManager.get() != nullptr) {
			uiManager->onMouseMove(e);
		}
	}

	if (e->type == SDL_MOUSEBUTTONDOWN) {
		if (e->button.button == SDL_BUTTON_LEFT) {
			leftPressed = true;
		}
		if (e->button.button == SDL_BUTTON_RIGHT) {
			rightPressed = true;
		}
	}

	if (e->type == SDL_MOUSEBUTTONUP) {
		if (e->button.button == SDL_BUTTON_LEFT) {
			leftPressed = false;
		}
		if (e->button.button == SDL_BUTTON_RIGHT) {
			rightPressed = false;
		}

		if (uiManager.get() != nullptr) {
			uiManager->onMouseRelease(e);
		}
	}
}

void MouseManager::setUIManager(std::shared_ptr<UIManager> uiManager)
{
	MouseManager::uiManager = uiManager;
}

int MouseManager::getMouseX()
{
	return mouseX;
}

int MouseManager::getMouseY()
{
	return mouseY;
}

bool MouseManager::isRightPressed()
{
	return rightPressed;
}

bool MouseManager::isLeftPressed()
{
	return leftPressed;
}
