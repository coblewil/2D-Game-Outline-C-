#include "MenuState.h"
#include "Handler.h"
#include "Assets.h"
#include "MouseManager.h"
#include "StateManager.h"
#include "UIManager.h"
#include "UIImageButton.h"
#include "Game.h"
#include "Assets.h"
#include "SubTexture.h"
#include "ClickListener.h"
#include "Handler.h"
#include "Text.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>

MenuState::MenuState(const std::shared_ptr<Handler>& handler):
	State{handler},
	uiManager{std::make_shared<UIManager>(handler)}
{
	MouseManager::setUIManager(uiManager);
	uiManager->addObject(std::make_shared<UIImageButton>(handler->getWidth() / 2-Assets::btn_start[0]->getSubTextureRect()->w/2, 0, Assets::btn_start[0]->getInherentSubTextureWidth(), Assets::btn_start[0]->getInherentSubTextureHeight(), Assets::btn_start, std::make_shared<ClickListener>([handler]() {
		MouseManager::setUIManager(nullptr);
		StateManager::setState(handler->getGame().lock()->gameState);
		})));
}

MenuState::~MenuState()
{
}

void MenuState::tick()
{
	uiManager->tick();
}

void MenuState::render(const std::shared_ptr<SDL_Renderer>& gRenderer)
{
	SDL_RenderCopy(gRenderer.get(), Assets::menuBackground.get(), NULL, NULL);
	Text::drawString(gRenderer, Assets::font12, "Press Deku Tree to Start", handler->getWidth() / 2, handler->getHeight() / 2 + 65, true, SDL_Color{ 236, 221, 27 });
	uiManager->render(gRenderer);
	SDL_RenderPresent(gRenderer.get());
}
