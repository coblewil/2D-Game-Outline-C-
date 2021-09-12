#include "UIImageButton.h"

UIImageButton::UIImageButton(float x, float y, int width, int height, std::vector<std::shared_ptr<SubTexture>> images, std::shared_ptr<ClickListener> clicker) :
	UIObject{x, y, width, height},
	images{images},
	clicker{clicker}
{
}

void UIImageButton::tick()
{
}

void UIImageButton::render(const std::shared_ptr<SDL_Renderer>& gRenderer)
{
	if (hovering) {
		SDL_RenderCopy(gRenderer.get(), images[1]->getTexturePtr(), images[1]->getSubTextureRectPtr(), &posRect);
	}
	else {
		SDL_RenderCopy(gRenderer.get(), images[0]->getTexturePtr(), images[0]->getSubTextureRectPtr(), &posRect);
	}
}

void UIImageButton::onClick()
{
	clicker->onClick();
}
