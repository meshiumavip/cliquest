#include <stdio.h>
#include <stdint.h>
#include "player.h"
#include "enemy.h"
#include "quest_error.h"

//プロトタイプ宣言
int32_t battle_scene(player_info_t *player_info);
int32_t attack(player_info_t *player_info);