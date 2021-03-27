#include <stdio.h>
#include <stdint.h>
#include "system.h"
#include "information.h"
#include "quest_error.h"

int32_t status_view(player_info_t *player_info){
    PRINT("名前: %s", player_info->status.name);
    PRINT("HP: %d", player_info->status.HP);
    PRINT("MP: %d", player_info->status.MP);
    PRINT("ATT: %d", player_info->status.ATT);
    PRINT("DEF: %d", player_info->status.DEF);
    PRINT("WIS: %d", player_info->status.WIS);
    PRINT("SPD: %d", player_info->status.SPD);
}