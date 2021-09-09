#include "lexer.h"

static char** lexeme_marcher(const char* line);
static lexer_types buffer_checker(const char* buffer, const char seek);

list* lexeme_generator(list* lines) {
    return NULL;
}

// HELPERS
static char** lexeme_marcher(const char* line) {
    const int line_len = strlen(line);
    char** segments = (char**)malloc(line_len * sizeof(char));
    char* buffer = (char*)malloc(line_len * sizeof(char));
    char* seek_char = (char*)malloc( sizeof(char));
    *(seek_char) = *(line + 0);

    // march through the charactor in the given line
    for (int i = 0; i < line_len; i++) {
        *(buffer + i) = *(seek_char);
        *(seek_char) = *(line + i + 1);
        if (*(seek_char)=='\0') break;
    }
}

static lexer_types buffer_checker(const char* buffer, const char seek) {
    if (*(buffer)=='\"') {
        if (seek=='\"') return string_literal;
        else return NO_TYPE;
    } //else if () {}
}
