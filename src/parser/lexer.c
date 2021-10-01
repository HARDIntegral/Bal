#include "lexer.h"

static char** lexeme_marcher(const char* line);
//static lexer_types buffer_checker(const char* buffer, const char seek);

list* lexeme_generator(list* lines) {
    list* lexemes = generate_list(STRING_ARR);
    
    node_l* iterator = lines->head;
    for (int i = 1; i < lines->size; i++) {
        if (append(lexemes, (void*)lexeme_marcher((char*)(iterator->data))) == FAILURE) break;
        iterator = iterator->next;
    }

    return lexemes;
}

// HELPERS
static char** lexeme_marcher(const char* line) { // for the love of God pls work
    const int line_len = strlen(line)+1;
    char** segments = (char**)malloc(line_len * sizeof(char));
    char* buffer = (char*)malloc(line_len * sizeof(char));
    char* seek_char = (char*)malloc( sizeof(char));
    *seek_char = *line;

    // march through the charactor in the given line
    int buffer_iterator = 0;
    int segment_iterator = 0;
    for (int i = 0; i < line_len; i++) {
        *(buffer + buffer_iterator++) = *(seek_char);
        *(seek_char) = *(line + i + 1);
        if (*(seek_char)=='\0') break;

        // just to test flushing the buffer
        if (i%4 == 0 && i > 3) {
            char* holder = (char*)malloc(++buffer_iterator * sizeof(char));
            memcpy(holder, buffer, buffer_iterator);
            *(holder + buffer_iterator) = '\0';
            

            buffer_iterator = 0;
            *(segments + segment_iterator++) = holder;
        }
    }
    char* leftover =(char*)malloc(3*(sizeof(char)));
    memcpy(leftover, buffer, buffer_iterator);
    *(segments + segment_iterator++) = leftover;
    *(segments + segment_iterator) = "END";

    free(buffer);           // how the fuk is this double-freed
    free(seek_char);
    buffer = NULL;
    seek_char = NULL;

    return segments;
}

//static lexer_types buffer_checker(const char* buffer, const char seek) {}
