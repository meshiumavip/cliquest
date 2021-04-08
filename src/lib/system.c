#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "system.h"
#include "scene.h"
#include "player.h"
#include "map.h"
#include "item.h"
#include "quest_error.h"

int32_t game_init(){
    LOG("");
    int32_t ret;
    player_info_t player_info;
    player_init(&player_info);
    ret = scene_title(&player_info);
}

void name_input(char *name){
    LOG("");
    char str[32];
    printf("入力：");
    fgets(str, 32, stdin);
    PRINT("\n");
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