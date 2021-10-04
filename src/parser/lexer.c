#include "lexer.h"

static char** lexeme_marcher(const char* line);
//static lexer_types buffer_checker(const char* buffer, const char seek);

list* lexeme_generator(list* lines) {
    list* lexemes = generate_list(STRING_ARR);
    while(lines->size > 0)
        if (append(lexemes, (void*)lexeme_marcher((char*)(pop(lines)->data))) == FAILURE) break;
    destroy_list(lines);
    return lexemes;
}

// HELPERS
static char** lexeme_marcher(const char* line) {
    int len = (int)strlen(line);
    if (len<1) return NULL;

    char** segments = (char**)malloc(sizeof(char*));
    char* buffer = (char*)malloc(32*sizeof(char*));
    char seek = *line;

    int buffer_iter, segment_iter = 0;
    for (int i = 1; i <= len; i++) {
        if (seek=='\0') break;
        buffer[buffer_iter] = seek;
        seek = line[i];
        printf("%s\n", buffer);
    }

    buffer = realloc(buffer, 0);
    return segments;
}

//static lexer_types buffer_checker(const char* buffer, const char seek) {}
