#include <stdio.h>
#include <malloc.h>

#define FAILURE -1
#define SUCCESS 1

typedef enum COMMON_TYPES COMMON_TYPES;
enum COMMON_TYPES {
    INTEGER,
    DOUBLE,
    FLOAT,
    CHAR,
    STRING,
    STRING_ARR,
    HASH,
};

typedef struct return_vals return_vals;
struct return_vals {
    void* data;
    COMMON_TYPES type;
};