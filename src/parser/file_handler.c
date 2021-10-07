#include "file_handler.h"

static char* sub_string(char* string, int pos, int len);

int verify_file(char* file_name) {
    int extension_len = 3;
    const char* extension = sub_string(file_name, strlen(file_name) - extension_len + 1, extension_len);
    if (extension==NULL) return FAILURE;
    
    const char* verification = ".bl";
    if (strcmp(extension, verification)!=0) return FAILURE;
    free(extension);
    return SUCCESS; 
}


// TODO: Fix the bug where the string is overwritten everytime loop is iterated
list* lineify(FILE* file) {
    list* line_list = generate_list(STRING);

    char* line = NULL;
    size_t len = 0;
    while (getline(&line, &len, file) != -1) {
        char* holder = (char*)malloc(strlen(line)*sizeof(char));
        strcpy(holder, line);
        if (append(line_list, (void*)holder)==FAILURE) return NULL;
    }
    fclose(file);
    free(line);

    return line_list;
}

FILE* open_file(char* file_name) {
    return fopen(file_name, "r");
}

// HELPERS
static char* sub_string(char* string, int pos, int len) {
    char* sub = malloc(len + 1);
    if (sub==NULL) return NULL;

    int i;
    for (i=0; i<len; i++) {
        *(sub + i) = *(string + pos - 1);
        string++;
    }
    *(sub + i) = '\0';
    return sub;
}
