#include "lexer.h"

static char** lexeme_marcher(char* line);
static int buffer_checker(const char* buffer);
static int seek_checker(const char seek);

list* lexeme_generator(list* lines) {
    return NULL;
}

// HELPERS
static char** lexeme_marcher(char* line) {
    const int line_len = strlen(line);
    char** segments = (char**)malloc(line_len * sizeof(char));
    char* buffer = (char*)malloc(line_len * sizeof(char));
    char* seek_char = (char*)malloc( sizeof(char));
    *(seek_char) = *(line + 0);

    // march through the charactor in the given line
    for (int i = 0; i < line_len; i++) {
        *(buffer + i) = *(seek_char);
        *(seek_char)
    }
}

static int buffer_checker(const char* buffer) {}

static int seek_checker(const char seek) {}