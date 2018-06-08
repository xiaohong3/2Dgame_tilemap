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
