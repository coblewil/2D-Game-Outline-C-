#include "Text.h"

std::shared_ptr<SDL_Texture> Text::loadFromRenderedText(const std::shared_ptr<SDL_Renderer>& gRenderer, std::shared_ptr<TTF_Font> font, std::string txt, SDL_Color c)
{
    std::shared_ptr<SDL_Texture> fTexture{nullptr};
    SDL_Surface* textSurface = TTF_RenderText_Solid(font.get(), txt.c_str(), c);
    if (textSurface == NULL)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else {
        fTexture = std::shared_ptr<SDL_Texture>(SDL_CreateTextureFromSurface(gRenderer.get(), textSurface), SDL_DestroyTexture);
        if (fTexture == nullptr || fTexture.get() == NULL) {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
    }

    SDL_FreeSurface(textSurface);
    return fTexture;
}

void Text::drawString(const std::shared_ptr<SDL_Renderer>& gRenderer, std::shared_ptr<TTF_Font> font, std::string text, int xPos, int yPos, bool center, SDL_Color c)
{
    std::shared_ptr<SDL_Texture> fontTexture = loadFromRenderedText(gRenderer, font, text, c);
    int x = xPos;
    int y = yPos;
    int w{};
    int h{};
    SDL_QueryTexture(fontTexture.get(), NULL, NULL, &w, &h);

    if (center) {
        x = xPos - w / 2;
        y = (yPos - h/ 2);
    }

    SDL_Rect r{x,y, w, h};

    SDL_RenderCopy(gRenderer.get(), fontTexture.get(), NULL, &r);
}
