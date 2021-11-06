#include "stack.h"

Stack* stack_init_s(COMMON_TYPES type, uint8_t size) {
    Stack* vec = (Stack*)malloc(sizeof(Stack));
    if (vec) {
        vec->data = NULL;
        vec->length = 0;
        vec->size = size;
        vec->type = type;
    }
    return vec;
}
Stack* stack_init(COMMON_TYPES type) {
    stack_init_s(type, 0);
}
void vec_free(Stack* vec) {
    if (vec->data) {
        free(vec->data);
        vec->data = NULL;
    }
    free(vec);
    vec = NULL;
}

void push(Stack* vec, void* data) {
    if (vec->length == vec->size) 
        vec->data = realloc(vec->data, sizeof(void*)*(vec->size*=2));
    vec->data[vec->length++] = data;
}
void* pop(Stack* vec) {
    return vec->data[vec->length--];
}
void reverse(Stack* vec) {
    for (int a = 0, b = vec->length; a < b; a++, b--) {
        void* tmp = vec->data[a];
        vec->data[a] = vec->data[b];
        vec->data[b] = tmp;
    }
}