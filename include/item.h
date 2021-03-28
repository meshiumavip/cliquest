#ifndef ITEM
#define ITEM

#include <stdio.h>
#include <stdint.h>
#include <information.h>

enum item{
    HP_PORTION = 0,
    MP_PORTION,
    SWORD,
    MITHRILL_SWORD,
    CRYSTAL_SWORD,
    ARMOR,
    MITHRILL_ARMOR,
    CRYSTAL_ARMOR,
};

typedef struct item_table{
    int32_t item_tag;
    char item_describe[126];
    status_t status;
    status_buf_t status_buf;
}item_table_t;

typedef struct equipment_table{
    int32_t equipment_tag;
    char itemequipment_name[32];
    char equipment_describe[126];
    int32_t HP;
    int32_t MP;
    int32_t ATT;
    int32_t DEF;
    int32_t WIS;
    int32_t SPD;
}equipment_table_t;

int32_t item_init(int32_t *player_info);
int32_t item_view(player_info_t *player_info);

#endif