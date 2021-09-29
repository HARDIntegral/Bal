#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <stdlib.h>
#include <string.h>
#include "../common/list.h"

int verify_file(char* file_name);
list* lineify(FILE* file);
FILE* open_file(char* file_name);

#endif // FILE_HANDLER_H