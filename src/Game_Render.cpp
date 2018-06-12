#include "Game.h"

void Game::on_render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // TODO: Render map and game object
    map.on_render(renderer, Camera::camera_control.get_x(), Camera::camera_control.get_y(), Camera::camera_control.get_w(), Camera::camera_control.get_h());

    SDL_RenderPresent(renderer);
}
