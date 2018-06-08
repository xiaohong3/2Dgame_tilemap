#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>
#include <iostream>

class TextureManager
{
    public:
        TextureManager();
        virtual ~TextureManager();
        static SDL_Texture* on_load(std::string file, SDL_Renderer* renderer);
        static void on_render(SDL_Renderer* renderer, SDL_Texture* texture, int dst_x, int dst_y);
        static void on_render(SDL_Renderer* renderer, SDL_Texture* texture, int src_x, int src_y, int dst_x, int dst_y, int w, int h);
};

#endif // TEXTUREMANAGER_H
