#ifndef LEXER_H
#define LEXER_H

#include <string.h>
#include "../common/hash.h"
#include "type_identifiers.h"

typedef struct lexeme lexeme;
struct lexeme {
    char* segment;
    lexer_types type;
};

list* lexeme_generator(list* lines);

#endif // LEXER_H