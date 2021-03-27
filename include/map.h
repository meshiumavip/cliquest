#ifndef MAP
#define MAP

#include <stdio.h>
#include <stdint.h>

#define ROW 10
#define COL 11
#define OPEN_SPACE 0
#define ROAD 1

typedef struct map{
    char map_name[32];
    int32_t map_tag;
    int32_t* field;
}map_t;

//map tag list
enum MAP_TAG{
    WORLD_MAP = 0,
};

//world_MAP
enum WORLD_MAP{
    CENTRAL = 2,
    NORTH_MEADOW = 3,
    EAST_MOUNTAIN = 4,
    WEST_DESERT = 5,
    SOUTH_PORT = 6,
    CRISTAL_CAVE = 7,
};

//プロトタイプ宣言
int32_t map_view(player_info_t *player_info);

#endif