#ifndef title
#define title

#include <stdio.h>
#include <stdint.h>
#include "system.h"
#include "information.h"

//enum
enum SCENE {
    SCENE_HOME = 100,
    SCENE_MENU,
    SCENE_MAP,
};

//プロトタイプ宣言
int32_t scene_view(list_t *list);
int32_t scene_selector(list_t *list, int32_t list_max, player_info_t *player_info);
int32_t scene_input(int32_t *num, int32_t list_max, list_t *list);
int32_t scene_change(list_t *list, player_info_t *player_info);

int32_t scene_prologue(player_info_t *player_info);
int32_t scene_title(player_info_t *player_info);
int32_t scene_menu(player_info_t *player_info);
int32_t scene_map(player_info_t *player_info);
int32_t scene_status(player_info_t *player_info);
int32_t scene_item(player_info_t *player_info);
int32_t scene_explore(player_info_t *player_info);
int32_t scene_move(player_info_t *player_info);

#endif