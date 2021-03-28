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
    status_t player_status = {"", 100, 100, 10, 10, 10, 10};
    int32_t player_item[20];
    item_init(player_item);
    player_item[0] = SWORD;
    player_item[1] = ARMOR;
    player_item[2] = HP_PORTION;
    player_item[3] = MP_PORTION;
    player_info_t player_info = {SOUTH_PORT, 0, WORLD_MAP, &player_status, player_item};
    ret = scene_title(&player_info);
}

void name_input(char *name){
    DEBUG("");
    char str[32];
    printf("名前を入力してください：");
    fgets(str, 32, stdin);
    strcpy(name, str);
}