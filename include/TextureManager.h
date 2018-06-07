#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "SDL2/SDL.h"
#include <string>

class TextureManager
{
    public:
        TextureManager();
        virtual ~TextureManager();
        static SDL_Texture* on_load(std::string file);
        static void on_render(SDL_Renderer* renderer, int dst_x, int dst_y);
        static void on_render(SDL_Renderer* renderer, int src_x, int src_y, int dst_x, int dst_y, int w, int h);
};

#endif // TEXTUREMANAGER_H
