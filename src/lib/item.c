#include <stdio.h>
#include <stdint.h>
#include "system.h"
#include "item.h"
#include "quest_error.h"

item_info_t item_info[20] = {
    {TIRE1  ,HP_PORTION         , NORMAL_ITEM      , "HPポーション"        , "HPが30回復する"      ,  30,   0,   0,   0,   0,   0},
    {TIRE1  ,MP_PORTION         , NORMAL_ITEM      , "MPポーション"        , "MPが30回復する"      ,   0,  30,   0,   0,   0,   0},
    {TIRE2  ,IRON_SWORD         , WEAPON           , "アイアンソード"              , "鉄製の剣"            ,   0,   0,  10,   0,   0,   0},
    {TIRE3  ,MITHRIL_SWORD      , WEAPON           , "ミスリルソード"      , "ミスリルの剣"        ,   0,   0,  20,   0,   0,   0},
    {TIRE4  ,CRYSTAL_SWORD      , WEAPON           , "クリスタルソード"    , "クリスタルの剣"      ,   0,   0,  30,   0,   0,   0},
    {TIRE2  ,LEATHRE_ARMOR      , ARMOR            , "レザーアーマー"            , "鉄製の鎧"            ,   0,   0,   0,  10,   0,   0},
    {TIRE3  ,MITHRIL_ARMOR      , ARMOR            , "ミスリルアーマー"    , "ミスリルの鎧"        ,   0,   0,   0,  20,   0,   0},
    {TIRE4  ,CRYSTAL_ARMOR      , ARMOR            , "クリスタルアーマー"  , "クリスタルの鎧"      ,   0,   0,   0,  30,   0,   0},
};

int32_t item_init(int32_t *player_item){
    LOG("");
    for(int32_t i=0; i<=20; i++){
        player_item[i] = -1;
    }
}

int32_t item_view(player_info_t *player_info){
    LOG("");
    SCENE("アイテム一覧");
    for(int32_t i=0; i<20; i++){
        if(player_info->item[i] == -1){
            break;
        }
        PRINT("%d: %s", i+1, item_info[player_info->item[i]].item_name);
    }
    PRINT("\n");
}