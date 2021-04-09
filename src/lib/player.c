#include <stdio.h>
#include <stdint.h>
#include "system.h"
#include "player.h"
#include "item.h"
#include "quest_error.h"

int32_t info_view(player_info_t *player_info){
    SCENE("%sのステータス", player_info->player_status.name);
    PRINT("HP: %d/%d", player_info->player_status.HP, player_info->player_status.MAX_HP);
    PRINT("MP: %d/%d", player_info->player_status.MP, player_info->player_status.MAX_MP);
    PRINT("ATT: %d", player_info->player_status.ATT);
    PRINT("DEF: %d", player_info->player_status.DEF);
    PRINT("WIS: %d", player_info->player_status.WIS);
    PRINT("SPD: %d", player_info->player_status.SPD);
    PRINT("\n");
}

int32_t player_init(player_info_t *player_info){
    int32_t ret = ERROR_SUCCESS;
    player_status_t player_status = {"", 200, 200, 100, 100, 10, 10, 10, 10};
    ret = item_init(player_info->item);
    player_info->item[0] = IRON_SWORD;
    player_info->item[1] = LEATHRE_ARMOR;
    player_info->item[2] = HP_PORTION;
    player_info->item[3] = MP_PORTION;
    player_info->global_location = 103;
    player_info->local_location = 0;
    player_info->player_status = player_status;
    return ret;
}