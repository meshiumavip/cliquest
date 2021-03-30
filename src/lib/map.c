#include <stdio.h>
#include <stdint.h>
#include <system.h>
#include <scene.h>
#include <map.h>
#include <color.h>
#include <quest_error.h>

/*field*/
int32_t world_map_field[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 1, 1, NORTH_MEADOW, 9},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 9},
    {0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 9},
    {0, 0, 0, 0, 0, NORTH_CITY, 0, 0, 0, CRISTAL_CAVE, 9},
    {0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 9},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 9},
    {0, 0, 1, 1, CENTRAL, 1, 1, 1, 1, EAST_MOUNTAIN, 9},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 9},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 9},
    {WEST_DESERT, 0, 0, 0, SOUTH_PORT, 0, 0, 0, 0, 0, 9},
};

int32_t NORTH_MEADOW_field[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
};

int32_t EAST_MOUNTAIN_field[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
};

int32_t WEST_DESERT_field[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
};

int32_t SOUTH_PORT_field[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
};

int32_t CRISTAL_CAVE_field[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
};

//map_list
map_t map_list[10] = {
    {"世界地図"              , WORLD_MAP         , WORLD_MAP  , (int32_t *)world_map_field},
    {""                      , -1                , -1         , NULL                      },
    {"セントラル"            , CENTRAL           , CITY       , NULL                      },
    {"北の街"                , NORTH_CITY        , CITY       , NULL                      },
    {"南の港"                , SOUTH_PORT        , CITY       , NULL                      },
    {"東の山"                , EAST_MOUNTAIN     , DUNGEON    , (int32_t *)world_map_field},
    {"西の砂漠"              , WEST_DESERT       , DUNGEON    , (int32_t *)world_map_field},
    {"北の平原"              , NORTH_MEADOW      , DUNGEON    , (int32_t *)world_map_field},
    {"クリスタルの洞窟"      , CRISTAL_CAVE      , DUNGEON    , (int32_t *)world_map_field},
};

void world_map_view(player_info_t *player_info){
    LOG("");
    PRINT("%s", map_list[WORLD_MAP].map_name);
    int32_t field_num;
    for(int32_t i = 0 ; i < 110; i++){
        field_num = map_list[WORLD_MAP].field[i];
        switch (field_num){
            case OPEN_SPACE:
                printf("  ");
                break;
            case ROAD:
                if(i == player_info->global_location){
                    YELLOW(" +");
                    break;
                }
                printf(" +");
                break;
            case 9:
                printf("\n");
                break;
            default:
                if(i == player_info->global_location){
                    YELLOW(" %d", field_num);
                    break;
                }
                if(map_list[field_num].map_type == CITY){
                    GREEN(" %d", field_num);
                }
                if(map_list[field_num].map_type == DUNGEON){
                    MAZENTA(" %d", field_num);
                }
                break;
        }
    }
    PRINT("---------------------------");
    PRINT("+: 道");
    for(int32_t i = 2 ; i < 9; i++){
        PRINT("%d: %s", i, map_list[i].map_name);
    }
    PRINT("自分の位置: 黄色");
    PRINT("");
}

void map_view(player_info_t *player_info){
    LOG("");
    PRINT("%s", map_list[player_info->global_location].map_name);
    for(int32_t i = 0 ; i < 110; i++){
       int32_t field_num = map_list[player_info->global_location].field[i];
        switch (field_num){
            case OPEN_SPACE:
                printf("  ");
                break;
            case ROAD:
                printf(" +");
                break;
            case 9:
                printf("\n");
                break;
            default:
                GREEN(" %d", field_num);
                break;
        }
    }
    if(player_info->global_location == WORLD_MAP){
    PRINT("---------------------------");
    }
}

int32_t move_north(player_info_t *player_info){
    LOG("");
    int32_t ret;
    int32_t next_location = player_info->global_location - 11;
    ret = worldmap_location_check(player_info, next_location);
    if(ret == ERROR_SUCCESS){
        PRINT("北へ移動");
        player_info->global_location = next_location;
    }
    list_t list[2] = {
        {1 , "menu", scene_menu},
        {-1 , "", NULL},
    };
    scene_change(list, player_info);
    return ret;
}

int32_t move_east(player_info_t *player_info){
    LOG("");
    int32_t ret;
    int32_t next_location = player_info->global_location + 1;
    ret = worldmap_location_check(player_info, next_location);
    if(ret == ERROR_SUCCESS){
        PRINT("東へ移動");
        player_info->global_location = next_location;
    }
    list_t list[2] = {
        {1 , "menu", scene_menu},
        {-1 , "", NULL},
    };
    scene_change(list, player_info);
    return ret;
}

int32_t move_south(player_info_t *player_info){
    LOG("");
    int32_t ret;
    int32_t next_location = player_info->global_location + 11;
    ret = worldmap_location_check(player_info, next_location);
    if(ret == ERROR_SUCCESS){
        PRINT("南へ移動");
        player_info->global_location = next_location;
    }
    list_t list[2] = {
        {1 , "menu", scene_menu},
        {-1 , "", NULL},
    };
    scene_change(list, player_info);
    return ret;
}

int32_t move_west(player_info_t *player_info){
    LOG("");
    int32_t ret;
    int32_t next_location = player_info->global_location - 1;
    ret = worldmap_location_check(player_info, next_location);
    if(ret == ERROR_SUCCESS){
        PRINT("西へ移動");
        player_info->global_location = next_location;
    }
    list_t list[2] = {
        {1 , "menu", scene_menu},
        {-1 , "", NULL},
    };
    scene_change(list, player_info);
    return ret;
}

int32_t worldmap_location_check(player_info_t *player_info, int32_t next_location){
    LOG("");
    int32_t ret = ERROR_SUCCESS;
    if(map_list[WORLD_MAP].field[next_location] == OPEN_SPACE){
        PRINT("行き止まりで移動できなかった。\n地図を確認しよう。");
        ret = ERROR_FAILUER;
        return ret;
    }
    return ret;
}