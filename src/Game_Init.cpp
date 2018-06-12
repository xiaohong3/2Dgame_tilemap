#include "Game.h"

bool Game::on_init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << SDL_GetError() << std::endl;
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        std::cout << IMG_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow("Tile map practice", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_W, WIN_H, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
        return false;
    }

    if (map.on_load("map/sample.map", renderer))
    {
        std::cout << "Map loaded successfully." << std::endl;
        Camera::camera_control = {0, 0, WIN_W, WIN_H, map.get_cols() * map.get_tsize() - WIN_W, map.get_rows() * map.get_tsize() - WIN_H};
    }

    return true;
}
