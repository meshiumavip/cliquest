#ifndef ENEMY
#define ENEMY

#include <stdio.h>
#include <stdint.h>
#include "map.h"
#include "player.h"
#include "quest_error.h"

//typedef
typedef struct enemy_status{
    int32_t MAX_HP;
    int32_t HP;
    int32_t MAX_MP;
    int32_t MP;
    int32_t ATT;
    int32_t DEF;
    int32_t WIS;
    int32_t SPD;
    int32_t EXP;
}enemy_status_t;

typedef struct enemy_status_buf{
    int32_t HP;
    int32_t MP;
    int32_t ATT;
    int32_t DEF;
    int32_t WIS;
    int32_t SPD;
}enemy_status_buf_t;

typedef struct enemy_table{
    int32_t enemy_tire;
    int32_t enemy_tag;
    char name[32];
    enemy_status_t enemy_status;
}enemy_table_t;

typedef struct encount_table{
    int32_t global_location;
    int32_t enemy1;
    int32_t encount_rate1;
    int32_t enemy2;
    int32_t encount_rate2;
    int32_t enemy3;
    int32_t encount_rate3;
}encount_table_t;


//enum
enum enemy{
    SLIME,
    METAL_SLIME,
    GOLDEN_SLIME,
    BAT,
    VAMPIRE_GENUS,
    VAMPIRE,
    WYVERN,
    DRAGON,
    CRYSTAL_DRAGON,
};

#endif