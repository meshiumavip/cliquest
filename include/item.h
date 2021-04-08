#ifndef ITEM
#define ITEM

#include <stdio.h>
#include <stdint.h>
#include "player.h"
#include "quest_error.h"

enum item{
    HP_PORTION = 0,
    MP_PORTION,
    IRON_SWORD,
    MITHRIL_SWORD,
    CRYSTAL_SWORD,
    LEATHRE_ARMOR,
    MITHRIL_ARMOR,
    CRYSTAL_ARMOR,
};

enum tire{
    TIRE1,
    TIRE2,
    TIRE3,
    TIRE4,
    TIRE5,
};

enum item_type{
    NORMAL_ITEM,
    KEY_ITEM,
    WEAPON,
    ARMOR,
};

typedef struct item_info{
    int32_t item_tire;
    int32_t item_tag;
    int32_t item_type;
    char item_name[33];
    char item_describe[129];
    int32_t HP;
    int32_t MP;
    int32_t ATT;
    int32_t DEF;
    int32_t WIS;
    int32_t SPD;
}item_info_t;

int32_t item_init(int32_t *player_info);
int32_t item_view(player_info_t *player_info);

#endif