#include "bal_compiler.h"
#include "parser/file_handler.h"
#include "parser/lexer.h"

// compiler flags
#define DEBUG       0x01    // 0b00000001
#define OPTIMIZE    0x02    // 0b00000010
#define TRANS_U     0x04    // 0b00000100
#define NEW_NAME    0x08    // 0b00001000
#define WARNINGS    0x10    // 0b00010000

static inputs* argument_handler(int num_args, char** args);
static int compile(char* file_name);

int comp(int argc, char** argv) {
    inputs* test = argument_handler(argc, argv);
    for (int i = 0; i < test->num_files; i++)
        if (compile(*(test->files + i)) == FAILURE) break;
    return SUCCESS;
}

void printString(node_l* input) {
    printf("%s ", (char *)(input->data));
}

static int compile(char* file_name) {
    // verify file can open
    FILE* file = open_file(file_name);
    if (file == NULL) return FAILURE;

    list* lines = lineify(file);
    march(lines, printString, 0);
    destroy_list(lines); 
    return SUCCESS;
}

// very ugly function
// fix later 
static inputs* argument_handler(int num_args, char** args) {
    uint8_t comp_options = 0;
    char** files = (char**)malloc(num_args * sizeof(char*));
    int files_pointer_locater = 0;

    for (int i = 1; i < num_args; i++) {
        if (strcmp(*(args+i),"-debug")==0 || strcmp(*(args+i),"-D")==0)
            comp_options |= DEBUG;
        if (strcmp(*(args+i),"-opt")==0 || strcmp(*(args+i),"-O")==0)
            comp_options |= OPTIMIZE;
        if (strcmp(*(args+i),"-tunit")==0 || strcmp(*(args+i),"-T")==0)
            comp_options |= TRANS_U;
        if (strcmp(*(args+i),"-name")==0 || strcmp(*(args+i),"-N")==0)
            comp_options |= NEW_NAME;
        if (strcmp(*(args+i),"-warn")==0 || strcmp(*(args+i),"-W")==0)
            comp_options |= WARNINGS;

        if (verify_file(*(args+i)) == SUCCESS) 
            *(files + files_pointer_locater++) = *(args+i);
    }

    inputs* new_inputs = (inputs*)malloc(sizeof(inputs));
    new_inputs->options = comp_options;
    new_inputs->files = files;
    new_inputs->num_files = files_pointer_locater;

    return new_inputs;
}
