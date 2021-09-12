#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class Display
{
private:
	//Variables
	std::shared_ptr<SDL_Window> gWindow;
	std::shared_ptr<SDL_Renderer> gRenderer;
	const std::string TITLE;
	const int SCREEN_WIDTH, SCREEN_HEIGHT;

	//Private Functions
	void createDisplay();
public:
	//Constructor/Destructor
	Display(std::string title, int width = 640, int height = 480);
	~Display();

	//Public Functions
	std::shared_ptr<SDL_Renderer> getRenderer();
};

