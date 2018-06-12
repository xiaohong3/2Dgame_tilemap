#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include "SDL2/SDL.h"
#include "Tile.h"
#include <fstream>
#include "TextureManager.h"

class Map
{
    public:
        Map();
        Map(std::string file);
        Map(std::string file, int cols, int rows, int tsize);
        virtual ~Map();
        bool on_load(std::string file, SDL_Renderer* renderer);
        void on_render(SDL_Renderer* renderer);
        void on_render(SDL_Renderer* renderer, int camera_x, int camera_y, int camera_w, int camera_h);

    public:
        int get_cols() {return cols;}
        int get_rows() {return rows;}
        int get_tsize() {return tsize;}

    protected:

    private:
        std::vector<Tile> tile_list;
        int get_tile(int row, int col);
        int cols;
        int rows;
        int tsize;
        SDL_Texture* texture;
};

#endif // MAP_H
