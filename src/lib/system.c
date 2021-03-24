#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "system.h"
#include "quest_error.h"
#include "scene.h"
#include "information.h"

int32_t game_init(){
    DEBUG("");
    int32_t ret;
    status_t player_status = {100, 100, 10, 10, 10, 10};
    player_info_t player_info = {CENTRAL, 0, player_status};
    ret = scene_title(&player_info);
}

int32_t scene_disctiptor(list_t *list){
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
            if(strlen(str) == 1){scene_disctiptor(list); continue;}; //未入力チェック
            *num=atoi(str);
            if(*num == 0){scene_disctiptor(list); continue;} //文字列を除外
            if(0 <= *num && *num <= list_max){
                break;
            }
            scene_disctiptor(list);
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