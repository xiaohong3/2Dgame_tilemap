#include "Game.h"

Game::Game()
{
    window = nullptr;
    renderer = nullptr;
    running = true;
}

Game::~Game()
{
    //dtor
}

void Game::on_exit()
{
    running = false;
}

void Game::on_event(SDL_Event* event)
{
    Event::on_event(event);
}

void Game::on_key_down(SDL_Keycode sys)
{
    switch (sys)
    {
        case SDLK_LEFT:
            Camera::camera_control.on_move(-5, 0);
            break;
        case SDLK_RIGHT:
            Camera::camera_control.on_move(5, 0);
            break;
        case SDLK_UP:
            Camera::camera_control.on_move(0, -5);
            break;
        case SDLK_DOWN:
            Camera::camera_control.on_move(0, 5);
            break;
    }
}

int Game::on_execute()
{
    if (!on_init())
    {
        return -1;
    }

    SDL_Event e;

    while (running)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            on_event(&e);
        }
        on_loop();
        on_render();
    }

    on_cleanup();
    return 0;
}

int main()
{
    Game test_game;
    return test_game.on_execute();
}
