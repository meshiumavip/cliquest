#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include "scene.h"
#include "map.h"
#include "item.h"
#include "quest_error.h"

int32_t scene_view(list_t *list){
    DEBUG("");
    for(int32_t i =0; i<20 ;i++){
        if(list[i].value == -1){
            break;
        }
        PRINT("%d: %s", list[i].value, list[i].key);
    }
    return ERROR_SUCCESS;
}

int32_t scene_selector(list_t *list, int32_t list_max, player_info_t *player_info){
    DEBUG("");
    int32_t ret;
    int32_t num;
    char *str;
    scene_input(&num, list_max, list);
    list[num-1].next_scene(player_info);
    return ret;
}

int32_t scene_input(int32_t *num, int32_t list_max, list_t *list){
    DEBUG("");
    int32_t ret;
    char str[4];//正常値は２桁＋入力時の改行＋終端文字＝４byte、5byte以上は不正
        while(1){
            printf("入力：");
            fgets(str, sizeof(str), stdin);
            if(str[strlen(str)-1] != '\n' ){while( getchar() != '\n');} //stdinに残った5byte以降の文字を回収
            if(strlen(str) == 1){scene_view(list); continue;}; //未入力チェック
            *num=atoi(str);
            if(*num == 0){scene_view(list); continue;} //文字列を除外
            if(0 <= *num && *num <= list_max){
                break;
            }
            scene_view(list);
        }
    return ret;
}

int32_t scene_change(list_t *list, player_info_t *player_info){
    DEBUG("");
    int32_t ret;
    int32_t num;
    list[0].next_scene(player_info);
    return ret;
}

int32_t scene_title(player_info_t *player_info){
    DEBUG("");
    int32_t ret;
    list_t list[2] = {
        {1 , "はじめる", scene_prologue},
        {-1 , "", NULL},
    };
    int32_t list_max = (sizeof(list) / sizeof(list_t)) - 1 ;
    ret = scene_view(list);
    ret = scene_selector(list, list_max, player_info);
    return ret;
}

int32_t scene_prologue(player_info_t *player_info){
    DEBUG("");
    PRINT("勇者の冒険が始まる");
    int32_t ret;
    name_input(player_info->status->name);
    scene_menu(player_info);
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
    ret = scene_view(list);
    ret = scene_selector(list, list_max, player_info);
}

int32_t scene_map(player_info_t *player_info){
    DEBUG("");
    map_view(player_info);
    scene_menu(player_info);
}

int32_t scene_status(player_info_t *player_info){
    DEBUG("");
    info_view(player_info);
    scene_menu(player_info);
}

int32_t scene_item(player_info_t *player_info){
    DEBUG("");
    item_view(player_info);
    scene_menu(player_info);
}

int32_t scene_explore(player_info_t *player_info){
    DEBUG("");    
}

int32_t scene_move(player_info_t *player_info){
    DEBUG("");
}