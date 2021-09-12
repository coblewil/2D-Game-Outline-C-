#include "Player.h"
#include "Assets.h"
#include "KeyManager.h"
#include "Game.h"
#include "Handler.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

Player::Player(const std::shared_ptr<Handler>& handler, float x, float y) :
	Creature(handler, x, y, Creature::DEFAULT_CREATURE_WIDTH, Creature::DEFAULT_CREATURE_HEIGHT)
{
	texture = Assets::player1;
	vel = DEFAULT_PLAYER_VEL;
	bounds->x = 16;
	bounds->y = 40;
	bounds->w = 32;
	bounds->h = 24;

	animUp = std::make_shared<Animation>(60, Assets::player_up);
	animDown = std::make_shared<Animation>(60, Assets::player_down);
	animLeft = std::make_shared<Animation>(60, Assets::player_left);
	animRight = std::make_shared<Animation>(60, Assets::player_right);
}

Player::~Player()
{
}

std::shared_ptr<Player> Player::copyPlayerSharedPtr()
{
	return shared_from_this();
}

void Player::tick()
{
	//temp
	animUp->tick();
	animDown->tick();
	animLeft->tick();
	animRight->tick();
	//end temp
	getInput();
	move();
	handler->getGameCamera()->centerOnEntity(copyPlayerSharedPtr());
	
}

void Player::getInput() {
	xMove = 0;
	yMove = 0;
	bool up = KeyManager::lastPressed[0] == KeyManager::up;
	bool down = KeyManager::lastPressed[0] == KeyManager::down;
	bool left = KeyManager::lastPressed[0] == KeyManager::left;
	bool right = KeyManager::lastPressed[0] == KeyManager::right;

	/*bool up = KeyManager::isKeyDown(KeyManager::up);
	bool down = KeyManager::isKeyDown(KeyManager::down);
	bool left = KeyManager::isKeyDown(KeyManager::left);
	bool right = KeyManager::isKeyDown(KeyManager::right);*/

	if (up) {
		yMove = -vel;
	}
	if (down) {
		yMove = vel;
	}
	if (left) {
		xMove = -vel;
	}
	if (right) {
		xMove = +vel;
	}
}

std::shared_ptr<Player> Player::create(const std::shared_ptr<Handler>& handler, float x, float y)
{
	return std::shared_ptr<Player>{new Player(handler, x, y)};
}


//temp
//SDL_Rect boundsRenderRect;

void Player::render(const std::shared_ptr<SDL_Renderer>& gRenderer)
{
	posRenderRect.x = static_cast<int>(x - handler->getGameCamera()->getXOffset());
	posRenderRect.y = static_cast<int>(y - handler->getGameCamera()->getYOffset());
	//SDL_SetRenderDrawColor(gRenderer.get(), 255, 0, 0, 255);
	/*SDL_RenderDrawLine(gRenderer.get(), 0, game.lock()->getHeight() / 2, (game.lock()->getWidth() / 2) - posRect.w/2, game.lock()->getHeight() / 2);
	SDL_RenderDrawLine(gRenderer.get(), (game.lock()->getWidth() / 2) + posRect.w / 2, game.lock()->getHeight() / 2, game.lock()->getWidth(), game.lock()->getHeight() / 2);
	SDL_RenderDrawLine(gRenderer.get(), (game.lock()->getWidth() / 2), 0, (game.lock()->getWidth() / 2), game.lock()->getHeight() / 2 - posRect.h/2);
	SDL_RenderDrawLine(gRenderer.get(), (game.lock()->getWidth() / 2), game.lock()->getHeight() / 2 + posRect.h / 2, (game.lock()->getWidth() / 2), game.lock()->getHeight());*/
	SDL_RenderCopy(gRenderer.get(), getCurrentAnimationFrame()->getTexturePtr(), getCurrentAnimationFrame()->getSubTextureRectPtr(), &posRenderRect);
	/*SDL_SetRenderDrawColor(gRenderer.get(), 255, 0, 0, 255);
	boundsRenderRect.x = x + bounds->x - handler->getGameCamera()->getXOffset();
	boundsRenderRect.y = y + bounds->y - handler->getGameCamera()->getYOffset();
	boundsRenderRect.w = bounds->w;
	boundsRenderRect.h = bounds->h;
	SDL_RenderFillRect(gRenderer.get(), &boundsRenderRect);*/
}

std::shared_ptr<SubTexture> Player::getCurrentAnimationFrame() const
{
	if (xMove < 0) {
		return animLeft->getCurrentFrame();
	}
	if (xMove > 0) {
		return animRight->getCurrentFrame();
	}
	if (yMove > 0) {
		return animDown->getCurrentFrame();
	}
	if (yMove < 0) {
		return animUp->getCurrentFrame();
	}
	return Assets::player1;
}

void Player::setX(int x)
{
	this->x = x;
}

void Player::setY(int y)
{
	this->y = y;
}
