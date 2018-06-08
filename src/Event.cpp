#include "Event.h"

Event::Event()
{
    //ctor
}

Event::~Event()
{
    //dtor
}

void Event::on_event(SDL_Event* event)
{
    switch (event->type)
    {
        case SDL_QUIT:
            on_exit();
            break;
    }
}
