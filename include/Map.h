#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include "SDL2/SDL.h"
#include "Tile.h"

class Map
{
    public:
        Map(std::string file);
        Map(std::string file, int cols, int rows, int tsize);
        virtual ~Map();
        bool on_load(std::string file, SDL_Renderer* renderer);
        void on_render(SDL_Renderer* renderer);

    protected:

    private:
        std::vector<Tile> tile_list;
        int cols;
        int rows;
        int tsize;
        SDL_Texture* texture;
};

#endif // MAP_H
