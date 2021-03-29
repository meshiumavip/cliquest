#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "system.h"
#include "scene.h"
#include "information.h"
#include "map.h"
#include "item.h"
#include "quest_error.h"

int32_t game_init(){
    DEBUG("");
    int32_t ret;
    status_t player_status = {"", 200, 200, 100, 100, 10, 10, 10, 10};
    int32_t player_item[20];
    item_init(player_item);
    player_item[0] = SWORD;
    player_item[1] = ARMOR;
    player_item[2] = HP_PORTION;
    player_item[3] = MP_PORTION;
    player_info_t player_info = {103, 0, &player_status, player_item};
    ret = scene_title(&player_info);
}

void name_input(char *name){
    debug_log(__FILE__, __LINE__, __func__, "");
    char str[32];
    printf("名前を入力してください：");
    fgets(str, 32, stdin);
    lntrim(str);
    strcpy(name, str);
}

int32_t debug_log(char *filename, int32_t line, const char *funcname, char *str){
    FILE *file;
    if ((file = fopen("cliquest.log" , "a")) == NULL) {
        printf("ファイルが開けませんでした");
        return ERROR_FAILUER;
    }
    fprintf(file , "%s:%d %s() :%s\n", filename, line, funcname, str);
    fclose(file);
    return 0;
}

void lntrim(char *str){
    char *p;  
    p = strchr(str, '\n');
    if(p != NULL){
        *p = '\0';
    }
} 