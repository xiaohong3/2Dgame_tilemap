#ifndef GAME_H
#define GAME_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Event.h"
#include "Define.h"
#include <iostream>

#include "Map.h"
#include "Camera.h"

class Game : public Event
{
    public:
        Game();
        virtual ~Game();
        int on_execute();
        bool on_init();
        void on_event(SDL_Event* event);
        void on_loop();
        void on_render();
        void on_cleanup();
        void on_exit();
        void on_key_down(SDL_Keycode sym);

    protected:

    private:
        bool running;
        SDL_Window* window;
        SDL_Renderer* renderer;

        Map down_layer;
        Map top_layer;
};

#endif // GAME_H
