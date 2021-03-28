#include <stdio.h>
#include <stdint.h>
#include <system.h>
#include <item.h>
#include <quest_error.h>

item_table_t item_table[100] = {
    {HP_PORTION, "HPが30回復する", {"HPポーション", 30, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
    {MP_PORTION, "MPが30回復する", {"MPポーション", 0, 30, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
    {SWORD, "鉄製の剣", {"ソード", 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
    {MITHRILL_SWORD, "ミスリルの剣", {"ソード", 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
    {CRYSTAL_SWORD, "クリスタルの剣", {"ソード", 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
    {ARMOR, "鉄製の鎧", {"アーマー", 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
    {MITHRILL_ARMOR, "ミスリルの鎧", {"アーマー", 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
    {CRYSTAL_ARMOR, "クリスタルの鎧", {"アーマー", 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},
};

equipment_table_t equipment_table[2] = {
};

int32_t item_init(int32_t *player_item){
    DEBUG("");
    for(int32_t i=0; i<=20; i++){
        player_item[i] = -1;
    }
}

int32_t item_view(player_info_t *player_info){
    DEBUG("");
    PRINT("アイテム一覧");
    for(int32_t i=0; i<20; i++){
        if(player_info->item[i] == -1){
            break;
        }
        PRINT("%d: %s", i+1, item_table[player_info->item[i]].status.name);
    }
}