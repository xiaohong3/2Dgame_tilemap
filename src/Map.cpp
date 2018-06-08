#include "Map.h"

Map::Map(std::string file)
{

}

Map::Map(std::string file, int cols, int rows, int tsize)
{
    this->cols = cols;
    this->rows = rows;
    this->tsize = tsize;
}

Map::~Map()
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    tile_list.clear();
}

bool Map::on_load(std::string file, SDL_Renderer* renderer)
{

}

void Map::on_render(SDL_Renderer* renderer)
{

}
