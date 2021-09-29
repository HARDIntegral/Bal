#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct inputs inputs;
struct inputs {
    uint8_t options;
    char** files;
    int num_files;
};

int comp(int argc, char** argv);