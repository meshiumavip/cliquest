#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "battle.h"
#include "scene.h"
#include "enemy.h"
#include "quest_error.h"

list_t battle_action[2] = {
    {1 , "攻撃", attack},
    {-1 , "", NULL},
};

int32_t encount(){
    LOG("");
    int32_t ret = ERROR_SUCCESS;
    encount_t encount;
    srand((uint32_t)time(NULL));
    for(int32_t i=0; i<10; i++){
        int32_t rand_num = rand() % 10;
        PRINT("rand_num %d : %d", i, rand_num);
        if(rand_num > 0){
            
        }
    }
    return ret;
}

int32_t battle_scene(player_info_t *player_info){
    LOG("");
    int32_t ret = ERROR_SUCCESS;
    ret = encount();
/*
    int32_t list_max = (sizeof(battle_action) / sizeof(list_t)) - 1 ;
    scene_view(battle_action);
    ret = scene_selector(battle_action, list_max, player_info);
*/
    DEBUG("");PRINT(" ret %d", ret);
    return ret;
}

int32_t attack(player_info_t *player_info){
    LOG("");
    DEBUG("");
}

