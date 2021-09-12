#include "Game.h"
#include "ImageLoader.h"
#include "Assets.h"
#include "SubTexture.h"
#include "StateManager.h"
#include "MouseManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <memory>
#include <iostream>
#include <time.h>

SDL_Point getSize(SDL_Texture* tex);

//Constructors/Destructors
Game::Game(std::string title, int width, int height):
	title{title},
	width{width},
	height{height},
	running{true},
	e{}
{
	
}

Game::~Game()
{
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

//Private Functions
void Game::init()
{
	display = std::make_shared<Display>(title, width, height);
	gRenderer = display->getRenderer();
	Assets::init(gRenderer);

	handler = std::make_shared<Handler>(copyGameSharedPtr());
	gameCamera = std::make_shared<GameCamera>(handler,0,0);
	

	KeyManager::init();

	gameState = std::make_shared<GameState>(handler);
	menuState = std::make_shared<MenuState>(handler);
	StateManager::setState(menuState);
}

std::shared_ptr<Game> Game::create(std::string title, int width, int height)
{
	return std::shared_ptr<Game>{new Game(title, width, height)};
}

std::shared_ptr<Game> Game::copyGameSharedPtr()
{
	return shared_from_this();
}

std::string Game::getTitle() const
{
	return title;
}

int Game::getWidth() const
{
	return width;
}

int Game::getHeight() const
{
	return height;
}

std::shared_ptr<GameCamera> Game::getGameCamera() const
{
	return gameCamera;
}

//Public Functions
void Game::run()
{
	init();

	while (running) {
		tick();
		render();
	}
}

//int x{ 0 };
//time_t then{time(NULL)};
//time_t now{ time(NULL) };
void Game::tick() {
	/*x += 1;
	now = time(NULL);
	if (now != then) {
		printf("fps: %d\n", x);
		x = 0;
		then = time(NULL);
	}*/
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			running = false;
		}

		KeyManager::handleEvent(&e);
		MouseManager::handleEvent(&e);
	}

	KeyManager::tick();

	if (StateManager::getState().get() != nullptr && StateManager::getState().get() != NULL) {
		StateManager::getState()->tick();
	}
}

void Game::render() {
	SDL_SetRenderDrawColor(gRenderer.get(), 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(gRenderer.get());

	if (StateManager::getState().get() != nullptr && StateManager::getState().get() != NULL) {
		StateManager::getState()->render(gRenderer);
	}

}

SDL_Point getSize(SDL_Texture* tex) {
	SDL_Point size{};
	SDL_QueryTexture(tex, NULL, NULL, &size.x, &size.y);
	return size;
}
