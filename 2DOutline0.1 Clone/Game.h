#pragma once
#include "Display.h"
#include "SpriteSheet.h"
#include "Assets.h"
#include "SubTexture.h"
#include "State.h"
#include "GameState.h"
#include "MenuState.h"
#include "StateManager.h"
#include "KeyManager.h"
#include "GameCamera.h"
#include "Handler.h"
#include <SDL.h>
#include <SDL_image.h>
#include <memory>
#include <iostream>

class Game : public std::enable_shared_from_this<Game>
{
private:
//Private Constructor	//so that every Game object is wrapped in a shared_ptr
	Game(std::string title, int width = 640, int height = 480);
	Game() = default;
	Game(const Game&) = delete;

//Private Variables
	std::string title;
	int width, height;
	bool running;

	//Display
	std::shared_ptr<Display> display;		
	
	//Events
	SDL_Event e;

	//Renderer
	std::shared_ptr<SDL_Renderer> gRenderer;

	//Handler
	std::shared_ptr<Handler> handler;

	//Camera
	std::shared_ptr<GameCamera> gameCamera;	

//Private Functions
	void init();

public:
//Destructor
	~Game();

//Public Variables
	//States
	std::shared_ptr<GameState> gameState;
	std::shared_ptr<MenuState> menuState;

//Public Functions
	
	//shared_ptr wrapper functions
	static std::shared_ptr<Game> create(std::string title, int width, int height);
	std::shared_ptr<Game> copyGameSharedPtr();

	//Getters
	std::string getTitle() const;
	int getWidth() const;
	int getHeight() const;
	std::shared_ptr<GameCamera> getGameCamera() const;

	void run();
	void tick();
	void render();
};

