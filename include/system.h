#ifndef SYSTEM
#define SYSTEM

#include <stdio.h>
#include <stdint.h>
#include "information.h"

#define DEBUG(...)  printf("%s:%d %s() ", __FILE__, __LINE__, __func__), printf(__VA_ARGS__), printf("\n")
#define PRINT(...)  printf(__VA_ARGS__), printf("\n")
#define INPUT(...)  printf("入力："), scanf("%d", &__VA_ARGS__)

//typedef
typedef int32_t (*SCENE)(player_info_t *player_info);

typedef struct list{
    int32_t value;
    char *key;
    SCENE next_scene;
}list_t;

//func
int32_t game_init();
void name_input(char *name);
int32_t scene_view(list_t *list);
int32_t scene_selector(list_t *list, int32_t list_max, player_info_t *player_info);
int32_t scene_input(int32_t *num, int32_t list_max, list_t *list);
int32_t scene_change(list_t *list, player_info_t *player_info);

#endif