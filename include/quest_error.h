#ifndef ERROR
#define ERROR

#include <stdio.h>
#include <stdint.h>

//define
#define ERROR_SUCCESS 0
#define ERROR_FAILUER 1

//typedef
typedef struct error{
    int32_t value;
    char *key;
}error_t;

//func

#endif