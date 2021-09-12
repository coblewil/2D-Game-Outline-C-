#include "StaticEntity.h"

StaticEntity::StaticEntity(const std::shared_ptr<Handler>& handler, float x, float y, int width, int height) :
	Entity(handler, x, y, width, height),
	posRenderRect{}
{
	posRenderRect.x = static_cast<int>(x);
	posRenderRect.y = static_cast<int>(y);
	posRenderRect.w = width;
	posRenderRect.h = height;
}

StaticEntity::~StaticEntity()
{
}
