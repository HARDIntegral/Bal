#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "bal_compiler.h"
#include "parser/file_handler.h"
#include "parser/lexer.h"

// compiler flags
#define DEBUG       0x01    // 0b00000001
#define OPTIMIZE    0x02    // 0b00000010
#define TRANS_U     0x04    // 0b00000100
#define NEW_NAME    0x08    // 0b00001000
#define WARNINGS    0x10    // 0b00010000

// rename to comp
int main(int argc, char** argv) {
    uint8_t test = argument_handler(argc, argv);
    return SUCCESS;
}

uint8_t argument_handler(int num_args, char** args) {
    uint8_t options = 0;
    printf("%d\n", num_args);
    for (int i = 0; i < num_args; i++) {
        printf("%s\n", args[i]);
        if (strcmp(*(args+i),"-debug")==0 || strcmp(*(args+i),"-D")==0)
            options += DEBUG;
        if (strcmp(*(args+i),"-opt")==0 || strcmp(*(args+i),"-O")==0)
            options += DEBUG;
        if (strcmp(*(args+i),"-tunit")==0 || strcmp(*(args+i),"-T")==0)
            options += DEBUG;
        if (strcmp(*(args+i),"-name")==0 || strcmp(*(args+i),"-N")==0)
            options += DEBUG;
        if (strcmp(*(args+i),"-warn")==0 || strcmp(*(args+i),"-W")==0)
            options += DEBUG;

    }

    return options;
}