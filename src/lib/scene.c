#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include "scene.h"
#include "map.h"
#include "item.h"
#include "quest_error.h"

void scene_view(list_t *list){
    LOG("");
    for(int32_t i =0; i<20 ;i++){
        if(list[i].value == -1){
            break;
        }
        PRINT("%d: %s", list[i].value, list[i].key);
    }
}

int32_t scene_selector(list_t *list, int32_t list_max, player_info_t *player_info){
    LOG("");
    int32_t ret = ERROR_SUCCESS;
    int32_t num;
    char *str;
    scene_input(&num, list_max, list);
    ret = list[num-1].next_scene(player_info);
    DEBUG("");PRINT(" ret %d");
    return ret;
}

void scene_input(int32_t *num, int32_t list_max, list_t *list){
    LOG("");
    char str[4];//正常値は２桁＋入力時の改行＋終端文字＝４byte、5byte以上は不正
        while(1){
            PRINT("---------------------------");
            printf("入力：");
            fgets(str, sizeof(str), stdin);
            PRINT("\n");
            if(str[strlen(str)-1] != '\n' ){while( getchar() != '\n');} //stdinに残った5byte以降の文字を回収
            if(strlen(str) == 1){scene_view(list); continue;}; //未入力チェック
            *num=atoi(str);
            if(*num == 0){scene_view(list); continue;} //文字列を除外
            if(0 <= *num && *num <= list_max){
                break;
            }
            scene_view(list);
        }
}

int32_t scene_change(list_t *list, player_info_t *player_info){
    LOG("");
    int32_t ret = ERROR_SUCCESS;
    int32_t num;
    ret = list[0].next_scene(player_info);
    return ret;
}

int32_t scene_title(player_info_t *player_info){
    LOG("");
    SCENE("スタート");
    int32_t ret = ERROR_SUCCESS;
    list_t list[2] = {
        {1 , "はじめる", scene_prologue},
        {-1 , "", NULL},
    };
    int32_t list_max = (sizeof(list) / sizeof(list_t)) - 1 ;
    scene_view(list);
    ret = scene_selector(list, list_max, player_info);
    return ret;
}

int32_t scene_prologue(player_info_t *player_info){
    LOG("");
    MESSAGE(
        "勇者の冒険が始まる\n"
        "あなたの名前を教えてください"
    );
    int32_t ret = ERROR_SUCCESS;
    name_input(player_info->player_status.name);
    ret = scene_menu(player_info);
    return ret;
}

int32_t scene_menu(player_info_t *player_info){
    LOG("");
    SCENE("メニュー");
    int32_t ret = ERROR_SUCCESS;
    list_t list[7] = {
        {1 , "全体マップ", scene_map},
        {2 , "マップ", scene_map},
        {3 , "ステータス", scene_status},
        {4 , "アイテム", scene_item},
        {5 , "探索", scene_explore},
        {6 , "移動", scene_move},
        {-1 , "", NULL},
    };
    int32_t list_max = sizeof(list) / sizeof(list_t);
    scene_view(list);
    ret = scene_selector(list, list_max, player_info);
}

int32_t scene_map(player_info_t *player_info){
    LOG("");
    int32_t ret = ERROR_SUCCESS;
    world_map_view(player_info);
    ret = scene_menu(player_info);
    return ret;
}

int32_t scene_status(player_info_t *player_info){
    LOG("");
    int32_t ret = ERROR_SUCCESS;
    info_view(player_info);
    ret = scene_menu(player_info);
    return ret;
}

int32_t scene_item(player_info_t *player_info){
    LOG("");
    int32_t ret = ERROR_SUCCESS;
    item_view(player_info);
    ret = scene_menu(player_info);
    return ret;
}

int32_t scene_explore(player_info_t *player_info){
    LOG("");
    MESSAGE("敵の気配がする・・・");
    SCENE("探索");
    int32_t ret;
    list_t list[4] = {
        {1 , "街の外周", battle_scene},
        {2 , "地下道", battle_scene},
        {3 , "メニューへ戻る", scene_menu},
        {-1 , "", NULL},
    };
    int32_t list_max = sizeof(list) / sizeof(list_t);
    scene_view(list);
    ret = scene_selector(list, list_max, player_info);
}

int32_t scene_move(player_info_t *player_info){
    LOG("");
    MESSAGE("どこへ移動する？");
    SCENE("移動");
    int32_t ret = ERROR_SUCCESS;
        list_t list[6] = {
            {1 , "北", move_north},
            {2 , "東", move_east},
            {3 , "南", move_south},
            {4 , "西", move_west},
            {5 , "メニューへ戻る", scene_menu},
            {-1 , "", NULL},
        };
    do{
        int32_t list_max = sizeof(list) / sizeof(list_t);
        scene_view(list);
        ret = scene_selector(list, list_max, player_info);
        DEBUG("");
        PRINT("ret %d",ret);
    }while(ret == ERROR_FAILUER);
}