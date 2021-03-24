#ifndef INFORMATION
#define INFORMATION

#include <stdio.h>
#include <stdint.h>

//enum
enum WORLD_MAP{
    CENTRAL = 100,
    NORTH,
    EAST,
    WEST,
    SOUTH,
};

enum ITEM{
    SWORD = 100,
    MITHRILL_SWORD,
    CRYSTAL_SWORD,
    ARMOR = 200,
    MITHRILL_ARMOR,
    CRYSTAL_ARMOR,
};

//typedef
typedef struct status{
    int32_t HP;
    int32_t MP;
    int32_t ATT;
    int32_t DEF;
    int32_t WIS;
    int32_t SPD;
}status_t;

typedef struct player_info{
    int32_t global_location;
    int32_t local_location;
    status_t status;
}player_info_t;

//プロトタイプ宣言
int32_t player_info();
int32_t glocal_map_view();
int32_t local_map_view();

#endif