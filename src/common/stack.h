#pragma once 

#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>
#include "common_header.h"

typedef struct Stack{
    void** data;
    uint8_t length;
    uint8_t size;
    COMMON_TYPES type;
} Stack;

Stack* stack_init_s(COMMON_TYPES type, uint8_t size);
Stack* stack_init(COMMON_TYPES type);
void vec_free(Stack* vec);

void push(Stack* vec, void* data);     // trusts the user to append data with right type
void* pop(Stack* vec);                 // trusts the user to know what data type they are handling
void reverse(Stack* vec); 