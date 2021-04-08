#ifndef INFORMATION
#define INFORMATION

#include <stdio.h>
#include <stdint.h>

//typedef
typedef struct player_status{
    char name[32];
    int32_t MAX_HP;
    int32_t HP;
    int32_t MAX_MP;
    int32_t MP;
    int32_t ATT;
    int32_t DEF;
    int32_t WIS;
    int32_t SPD;
}player_status_t;

typedef struct player_status_buf{
    int32_t HP;
    int32_t MP;
    int32_t ATT;
    int32_t DEF;
    int32_t WIS;
    int32_t SPD;
}player_status_buf_t;

typedef struct player_info{
    int32_t global_location;
    int32_t local_location;
    player_status_t player_status;
    int32_t item[20];
}player_info_t;

//プロトタイプ宣言
int32_t info_view(player_info_t *player_info);
int32_t player_init(player_info_t *player_info);

#endif