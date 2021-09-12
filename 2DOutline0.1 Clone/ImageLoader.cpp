#include "ImageLoader.h"

std::shared_ptr<SDL_Texture> ImageLoader::loadImage(const std::shared_ptr<SDL_Renderer>& gRenderer, std::string path)
{
	std::shared_ptr<SDL_Texture> newTexture{ nullptr };
	
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Create texture from surface pixels
        newTexture = std::shared_ptr<SDL_Texture>{ SDL_CreateTextureFromSurface(gRenderer.get(), loadedSurface), SDL_DestroyTexture};
        if (newTexture.get() == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    return newTexture;
}
