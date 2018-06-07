#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include "SDL2/SDL.h"
#include "Tile.h"

class Map
{
    public:
        Map();
        virtual ~Map();
        bool load(std::string file);
        void render(SDL_Renderer* renderer);

    protected:

    private:
        std::vector<Tile> tile_list;
};

#endif // MAP_H
