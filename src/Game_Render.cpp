#include "Game.h"

void Game::on_render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // TODO: Render map and game object

    SDL_RenderPresent(renderer);
}
