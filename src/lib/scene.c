#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "system.h"
#include "scene.h"

int32_t scene_title(player_info_t *player_info){
    DEBUG("");
    int32_t ret;
    list_t list[2] = {
        {1 , "はじめる", scene_prologue},
        {-1 , "", NULL},
    };
    int32_t list_max = (sizeof(list) / sizeof(list_t)) - 1 ;
    ret = scene_disctiptor(list);
    ret = scene_selector(list, list_max, player_info);
    return ret;
}

int32_t scene_prologue(player_info_t *player_info){
    DEBUG("");
    PRINT("勇者の冒険が始まる");
    int32_t ret;
    list_t list[2] = {
        {1 , "メニュー", scene_menu},
        {-1 , "", NULL},
    };
    ret = scene_change(list, player_info);
    return ret;
}

int32_t scene_menu(player_info_t *player_info){
    DEBUG("");
    int32_t ret;
    int32_t input;
    list_t list[6] = {
        {1 , "マップ", scene_map},
        {2 , "ステータス", scene_status},
        {3 , "アイテム", scene_item},
        {4 , "探索", scene_explore},
        {5 , "移動", scene_move},
        {-1 , "", NULL},
    };
    int32_t list_max = sizeof(list) / sizeof(list_t);
    ret = scene_disctiptor(list);
    ret = scene_selector(list, list_max, player_info);
}

int32_t scene_map(player_info_t *player_info){
    DEBUG("");
}

int32_t scene_status(player_info_t *player_info){
    DEBUG("");    
}

int32_t scene_item(player_info_t *player_info){
    DEBUG("");
}

int32_t scene_explore(player_info_t *player_info){
    DEBUG("");    
}

int32_t scene_move(player_info_t *player_info){
    DEBUG("");
}