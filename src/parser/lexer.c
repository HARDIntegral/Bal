#include "lexer.h"

static char** lexeme_marcher(const char* line);
//static lexer_types buffer_checker(const char* buffer, const char seek);

list* lexeme_generator(list* lines) {
    list* lexemes = generate_list(STRING_ARR);
    while(lines->size > 0) {
        node_l* tmp = pop(lines);
        if (tmp == NULL) break;
        if (append(lexemes, (void*)lexeme_marcher((char*)(tmp->data))) == FAILURE) break;
        destroy_node(tmp);
    }
    destroy_list(lines);
    return lexemes;
}

// HELPERS
static char** lexeme_marcher(const char* line) {
    int len = (int)strlen(line);
    int buffer_size = 32;
    if (len<1) return NULL;

    char** segments = (char**)malloc(sizeof(char*));
    char* buffer = (char*)malloc(buffer_size*sizeof(char*));
    memset(buffer, '\0', buffer_size);
    char seek = *line;

    int buffer_iter = 0;
    int segment_iter = 0;
    for (int i = 1; i <= len; i++) {
        if (seek=='\0') break;
        if (seek=='\n' || seek=='\r') continue;
        if (buffer_iter >= buffer_size) buffer = (char*)realloc(buffer, buffer_size*=2);
        buffer[buffer_iter++] = seek;
        seek = line[i];
        printf("%s\n", buffer);
    }

    buffer = realloc(buffer, 0);
    return segments;
}

//static lexer_types buffer_checker(const char* buffer, const char seek) {}
