#include <stdio.h>
#include <stdint.h>
#include "enemy.h"
#include "item.h"
#include "quest_error.h"


enemy_table_t enemy_table[20]={
    { TIRE1, SLIME              , "スライム"              ,  10,   10,   0,   0,   1,   1,   1,   1,   1},
    { TIRE2, METAL_SLIME        , "メタルスライム"        ,  10,  10,  10,  10, 100, 100, 100, 100,   10},
    { TIRE3, GOLDEN_SLIME       , "ゴールデンスライム"    ,  10,  10,  10,  10, 999, 999, 999, 999,  999},
    { TIRE1, SLIME              , "ポイズンバット"        ,  10,   10,  20,  20,   1,   1,   1,   1,   2},
    { TIRE2, VAMPIRE_GENUS      , "吸血鬼の眷属"          , 100,  100, 200, 200,  20,  20,  40,  40,  20},
    { TIRE3, VAMPIRE            , "吸血鬼"                , 200,  200, 400, 400, 200, 200, 400, 400, 200},
    { TIRE2, WYVERN             , "ワイバーン"            , 200,  200, 100, 100,  40,  40,  20,  20,  20},
    { TIRE3, DRAGON             , "ドラゴン"              , 400,  400, 200, 200, 400, 400, 200, 200, 200},
    { TIRE4, CRYSTAL_DRAGON     , "クリスタルドラゴン"    , 800,  800, 400, 400, 800, 800, 400, 400, 400},
};

encount_table_t encount_table[10]={
    {CENTRAL        , SLIME          , 0.5, BAT            , 0.4, METAL_SLIME          , 0.1},
};

