#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>

class KeyManager
{
private:
//Private Variables
	//https://wiki.libsdl.org/SDL_GetKeyboardState
	static Uint8* oldKeys;
	static const Uint8* keys;
	static int keysSize;

public:
//Initializers
	static void init();

//Public Variables
	const static SDL_Scancode up;
	const static SDL_Scancode down;
	const static SDL_Scancode left;
	const static SDL_Scancode right;
	
	static std::vector<SDL_Scancode> lastPressed;
	static SDL_Scancode lastReleased;
//Public Functions
	static void handleEvent(SDL_Event* e);

	static bool isKeyDown(SDL_Scancode k);
	static bool isKeyPressed(SDL_Scancode k);
	static bool isKeyReleased(SDL_Scancode k);
	static bool isKeyHeld(SDL_Scancode k);
	static bool isKeyRepeated(SDL_Scancode k);

	static void tick();
};

