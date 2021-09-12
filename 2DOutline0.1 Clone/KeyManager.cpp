#include "KeyManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

Uint8* KeyManager::oldKeys{ nullptr };
const Uint8* KeyManager::keys{ nullptr };
int KeyManager::keysSize{ 0 };
std::vector<SDL_Scancode> KeyManager::lastPressed{1};
SDL_Scancode KeyManager::lastReleased{};

const SDL_Scancode KeyManager::up{ SDL_SCANCODE_UP };
const SDL_Scancode KeyManager::down{ SDL_SCANCODE_DOWN };
const SDL_Scancode KeyManager::left{ SDL_SCANCODE_LEFT };
const SDL_Scancode KeyManager::right{ SDL_SCANCODE_RIGHT };

void KeyManager::init() {
	keys = SDL_GetKeyboardState(&keysSize);
	delete[] oldKeys;
	oldKeys = new Uint8[keysSize];
	std::memcpy(oldKeys, keys, sizeof(Uint8) * keysSize);
}

void KeyManager::handleEvent(SDL_Event* e)
{
	if (e->type == SDL_KEYDOWN) {
		lastPressed.insert(lastPressed.begin(), e->key.keysym.scancode);
	}
	if (e->type == SDL_KEYUP) {
		lastPressed.erase(std::remove(lastPressed.begin(), lastPressed.end(), e->key.keysym.scancode), lastPressed.end());
		lastPressed.emplace_back(); //pushing back an empty element so that dereferences vector at index 0 doesn't result in an error
		lastReleased = e->key.keysym.scancode;
	}
}

bool KeyManager::isKeyDown(SDL_Scancode k)
{
	//if (keys[k]) {
		//lastPressed[0] = k;
	//}
	return keys[k];
}

bool KeyManager::isKeyPressed(SDL_Scancode k)
{
	return !oldKeys[k] && keys[k];
}

bool KeyManager::isKeyReleased(SDL_Scancode k)
{
	return oldKeys[k] && !keys[k];
}

bool KeyManager::isKeyHeld(SDL_Scancode k)
{
	return oldKeys[k] && keys[k]; //TO-DO, maybe have something to check if the key has been down for a while, instead of just one tick
}

bool KeyManager::isKeyRepeated(SDL_Scancode k)
{
	printf("This function is not yet defined. bool KeyManager::isKeyRepeated(SDL_Scancode k).");
	return false;
	//TO-DO finish this
}

void KeyManager::tick()
{
	//keys = SDL_GetKeyboardState(NULL);
	/*if (isKeyDown(up)) { printf("keyDown\n"); };
	if (isKeyPressed(up)) { printf("keyPressed\n"); };
	if (isKeyReleased(up)) { printf("keyReleased\n"); };
	if (isKeyHeld(up)) { printf("keyHeld\n"); };*/
	std::memcpy(oldKeys, keys, sizeof(Uint8) * keysSize); //WARNING: oldKeys must be updated either BEFORE PollEvents or PumpEvents or AFTER all state bools are checked
}
