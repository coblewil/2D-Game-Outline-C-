#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <memory>

class Text
{
public:

	static std::shared_ptr<SDL_Texture> loadFromRenderedText(const std::shared_ptr<SDL_Renderer>& gRenderer, std::shared_ptr<TTF_Font> font, std::string txt, SDL_Color c);

	static void drawString(const std::shared_ptr<SDL_Renderer>& gRenderer, std::shared_ptr<TTF_Font> font, std::string text, int xPos, int yPos, bool center = true, SDL_Color c = SDL_Color{0,0,0});
};

