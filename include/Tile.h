#ifndef TILE_H
#define TILE_H

enum
{
    TILE_TYPE_NONE,
    TILE_TYPE_NORMAL,
    TILE_TYPE_BLOCK
};

struct Tile
{
    public:
        Tile()
        {
            tile_id = 0;
            tile_type_id = TILE_TYPE_NONE;
        }

        int tile_id;
        int tile_type_id;
};

#endif // TILE_H
