#include <stdio.h>
#include <malloc.h>

#define FAILURE -1
#define SUCCESS 1

typedef enum TYPES TYPES;
enum TYPES {
    INTEGER,
    DOUBLE,
    FLOAT,
    CHAR,
    STRING,
};