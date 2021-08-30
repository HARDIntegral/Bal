#include "lexer.h"

static char** lexeme_marcher(char* line);

list* lexeme_generator(list* lines) {
    return NULL;
}

// HELPERS
static char** lexeme_marcher(char* line) {
    const int line_len = strlen(line);
    char** segments = (char**)malloc(line_len * sizeof(char));
    char* buffer = (char*)malloc(line_len * sizeof(char));
    
    // march through the charactor in the given line
    for (int i = 0; i < line_len; i++) {
        break;
    }
}