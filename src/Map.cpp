#include "Map.h"

Map::Map()
{
    cols = 0;
    rows = 0;
    tsize = 0;
    texture = nullptr;
}

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
    tile_list.clear();

    std::ifstream ifs;
    ifs.open(file, std::ios_base::in);

    if (!ifs)
    {
        return false;
    }

    std::string img_file;

    ifs >> img_file;

    texture = TextureManager::on_load(img_file, renderer);

    if (texture == nullptr)
    {
        return false;
    }

    ifs >> this->rows >> this->cols >> this->tsize;

    if (this->rows == 0 || this->cols == 0 || this->tsize == 0)
    {
        ifs.close();
        return false;
    }

    for (int i = 0; i < this->rows; ++i)
    {
        for (int j = 0; j < this->cols; ++j)
        {
            Tile tile;
            ifs >> tile.tile_id;
            tile.tile_type_id = TILE_TYPE_NORMAL;
            tile_list.push_back(tile);
        }
    }

    ifs.close();
    return true;
}

void Map::on_render(SDL_Renderer* renderer)
{
    for (int i = 0; i < tile_list.size(); ++i)
    {
        const Tile tile = tile_list.at(i);
        if (tile.tile_id != 0)
        {
            int src_x = (tile.tile_id - 1) * tsize;
            int src_y = 0;
            int dst_x = (i % cols) * tsize;
            int dst_y = (i / rows) * tsize;
            TextureManager::on_render(renderer, texture, src_x, src_y, dst_x, dst_y, tsize, tsize);
        }
    }
}

void Map::on_render(SDL_Renderer* renderer, int camera_x, int camera_y, int camera_w, int camera_h)
{
    int start_col = camera_x / tsize;
    int end_col = camera_w / tsize;
    int start_row = camera_y / tsize;
    int end_row = camera_h / tsize;
    int offset_x = -camera_x + start_col * tsize;
    int offset_y = -camera_y + start_row * tsize;

    for (int i = start_col; i <= end_col; ++i)
    {
        for (int j = start_row; j <= end_row; ++j)
        {
            const Tile tile = tile_list.at(get_tile(j, i));
            int src_x = (tile.tile_id - 1) * tsize;
            int src_y = 0;
            int dst_x = (i - start_col) * tsize + offset_x;
            int dst_y = (j - start_row) * tsize + offset_y;
            TextureManager::on_render(renderer, texture, src_x, src_y, dst_x, dst_y, tsize, tsize);
        }
    }
}

int Map::get_tile(int row, int col)
{
    return row * cols + col;
}
