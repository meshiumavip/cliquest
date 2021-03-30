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
    int32_t map_type;
    int32_t* field;
}map_t;

//map tag list
enum MAP_TAG{
    WORLD_MAP = 0,
    CENTRAL = 2,
    NORTH_CITY,
    SOUTH_PORT,
    EAST_MOUNTAIN,
    WEST_DESERT,
    NORTH_MEADOW,
    CRISTAL_CAVE,
};

//world_MAP
enum MAP_TYPE{
    CITY = 0,
    DUNGEON = 1,
};

//プロトタイプ宣言
int32_t worldmap_location_check(player_info_t *player_info, int32_t next_location);
void world_map_view(player_info_t *player_info);
void map_view(player_info_t *player_info);
int32_t move_north(player_info_t *player_info);
int32_t move_east(player_info_t *player_info);
int32_t move_south(player_info_t *player_info);
int32_t move_west(player_info_t *player_info);
#endif