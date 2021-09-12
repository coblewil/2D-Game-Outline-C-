#include "Entity.h"
#include "Handler.h"

Entity::Entity(const std::shared_ptr<Handler>& handler, float x, float y, int width, int height):
	handler{handler},
	x{x},
	y{y},
	width{width},
	height{height},
	bounds{ std::make_shared<SDL_Rect>() }
{
	bounds->x = 0;
	bounds->y = 0;
	bounds->w = width;
	bounds->h = height;
}

Entity::~Entity()
{
}

int Entity::getWidth() const
{
	return width;
}

int Entity::getHeight() const
{
	return height;
}

bool Entity::checkEntityCollisions(float xOffset, float yOffset)
{
	for (std::shared_ptr<Entity> e : handler->getWorld()->getEntityManager()->getEntities()) {
		if (e.get() == this) {
			continue;
		}
		if (SDL_HasIntersection(e->getCollisionBounds(0, 0).get(), getCollisionBounds(xOffset, yOffset).get())) {
			return true;
		}
	}

	return false;
}

std::shared_ptr<SDL_Rect> Entity::getCollisionBounds(float xOffset, float yOffset) const
{
	std::shared_ptr<SDL_Rect> r = std::make_shared<SDL_Rect>();
	r->x = static_cast<int> (x + bounds->x + xOffset);
	r->y = static_cast<int> (y + bounds->y + yOffset);
	r->w = bounds->w;
	r->h = bounds->h;
	return r;
}

float Entity::getX() const
{
	return x;
}

float Entity::getY() const
{
	return y;
}
