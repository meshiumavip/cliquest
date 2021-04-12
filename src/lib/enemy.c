#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "system.h"
#include "enemy.h"
#include "item.h"
#include "quest_error.h"

enemy_table_t enemy_table[ENEMY_TABLE]={
    { TIRE1, SLIME              , "スライム"              ,  10,   10,   0,   0,   1,   1,   1,   1,   1},
    { TIRE2, METAL_SLIME        , "メタルスライム"        ,  10,  10,  10,  10, 100, 100, 100, 100,   10},
    { TIRE3, GOLDEN_SLIME       , "ゴールデンスライム"    ,  10,  10,  10,  10, 999, 999, 999, 999,  999},
    { TIRE1, BAT                , "バット"                ,  10,   10,  20,  20,   1,   1,   1,   1,   2},
    { TIRE2, VAMPIRE_GENUS      , "吸血鬼の眷属"          , 100,  100, 200, 200,  20,  20,  40,  40,  20},
    { TIRE3, VAMPIRE            , "吸血鬼"                , 200,  200, 400, 400, 200, 200, 400, 400, 200},
    { TIRE2, WYVERN             , "ワイバーン"            , 200,  200, 100, 100,  40,  40,  20,  20,  20},
    { TIRE3, DRAGON             , "ドラゴン"              , 400,  400, 200, 200, 400, 400, 200, 200, 200},
    { TIRE4, CRYSTAL_DRAGON     , "クリスタルドラゴン"    , 800,  800, 400, 400, 800, 800, 400, 400, 400},
};

encount_table_t encount_table[ENCOUNT_TABLE]={
    {CENTRAL , SLIME, BAT, METAL_SLIME},
};

int32_t encount(player_info_t *player_info){
    LOG("");
    int32_t ret = ERROR_SUCCESS;
    int32_t rand_num = 0;
    int32_t i = 0;
    int32_t encount_enemy[ENCOUNT_ENEMY];
    for(i = 0; i < ENCOUNT_TABLE; i++){
        if(player_info->global_location == encount_table[i].global_location){
            DEBUG(" i: %d\n", i);
            break;
        }else{
            i = 0;
            break;
        }

    }
    srand((uint32_t)time(NULL));
    for(int32_t j = 0 ; j < ENCOUNT_ENEMY; j++){
        rand_num = rand() % 10;
        DEBUG(" rand_num: %d\n", rand_num);
        if(rand_num >= 5){
        DEBUG("\n");
            encount_enemy[j] = encount_table[i].enemy1;
        }else if(rand_num >= 1){
        DEBUG("\n");
            encount_enemy[j] = encount_table[i].enemy2;
        }else{
        DEBUG("\n");
            encount_enemy[j] = encount_table[i].enemy3;
        }
        DEBUG(" encount_enemy[%d]: %s\n", j, enemy_table[encount_enemy[j]].name);
    }
    return ret;
}