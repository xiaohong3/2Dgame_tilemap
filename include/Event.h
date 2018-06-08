#ifndef EVENT_H
#define EVENT_H

#include "SDL2/SDL.h"

class Event
{
    public:
        Event();
        virtual ~Event();
        virtual void on_event(SDL_Event* event);
        virtual void on_exit() = 0;

    protected:

    private:
};

#endif // EVENT_H
