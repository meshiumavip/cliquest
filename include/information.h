#ifndef INFORMATION
#define INFORMATION

#include <stdio.h>
#include <stdint.h>

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
    char name[32];
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
    int32_t map_tag;
    status_t status;
}player_info_t;

//プロトタイプ宣言
int32_t status_view(player_info_t *player_info);
#endif