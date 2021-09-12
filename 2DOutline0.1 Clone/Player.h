#pragma once
#include "Creature.h"
#include "Entity.h"
#include "SubTexture.h"
#include "Animation.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <memory>

class Handler;
class Player : public Creature, public std::enable_shared_from_this<Player>
{
private:
//Private Constructors/Destructors
	Player(const std::shared_ptr<Handler>& handler, float x, float y);

//Private Variables
	const float DEFAULT_PLAYER_VEL{ 3.0f };
	SDL_Rect boundsRenderRect;

	std::shared_ptr<Animation> animUp, animDown, animLeft, animRight, animFaceForward, animFaceLeft, animFaceRight;

//Private Functions
	void getInput();
public:
//Create Function to access Private Constructor
	static std::shared_ptr<Player> create(const std::shared_ptr<Handler>& handler, float x, float y);

	~Player();

//Public Functions
	std::shared_ptr<Player> copyPlayerSharedPtr();
	virtual void tick() override;
	virtual void render(const std::shared_ptr<SDL_Renderer>& gRenderer) override;
	
	//Getters
	std::shared_ptr<SubTexture> getCurrentAnimationFrame() const;

	//Setters
	void setX(int x);
	void setY(int y);
};

