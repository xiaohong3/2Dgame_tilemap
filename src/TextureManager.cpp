#include "TextureManager.h"

TextureManager::TextureManager()
{
    //ctor
}

TextureManager::~TextureManager()
{
    //dtor
}

SDL_Texture* TextureManager::on_load(std::string file, SDL_Renderer* renderer)
{
    SDL_Surface* temp = IMG_Load(file.c_str());
    SDL_Texture* texture = nullptr;
    texture = SDL_CreateTextureFromSurface(renderer, temp);

    if (texture == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(temp);
    temp = nullptr;

    return texture;
}

void TextureManager::on_render(SDL_Renderer* renderer, SDL_Texture* texture, int dst_x, int dst_y)
{
    SDL_Rect dst;
    dst.x = dst_x;
    dst.y = dst_y;
    SDL_QueryTexture(texture, nullptr, nullptr, &dst.w, &dst.h);
    SDL_RenderCopy(renderer, texture, nullptr, &dst);
}

void TextureManager::on_render(SDL_Renderer* renderer, SDL_Texture* texture, int src_x, int src_y, int dst_x, int dst_y, int w, int h)
{
    SDL_Rect src = {src_x, src_y, w, h};
    SDL_Rect dst = {dst_x, dst_y, w, h};
    SDL_RenderCopy(renderer, texture, &src, &dst);
}
