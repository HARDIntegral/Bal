#include "file_handler.h"

static FILE* open_file(char* file_name);
static char* sub_string(char* string, int pos, int len);

int verify_file(char* file_name) {
    int extension_len = 3;
    const char* extension = sub_string(file_name, strlen(file_name) - extension_len, extension_len);
    if (extension==NULL) return FAILURE;
    
    const char* verification = ".bt";
    if (strcmp(extension, verification)!=0) return FAILURE;
    return SUCCESS; 
}

list* lineify(char* file_contents) {
    FILE* file = fopen(file_contents, "r");
    if (file == NULL) return NULL;

    list* line_list = generate_list(STRING);

    char* line = NULL;
    size_t len = 0;
    while (getline(&line, &len, file) != -1)
        if (append(line_list, (void*)line)==FAILURE) return NULL;
    fclose(file);

    return line_list;
}

// HELPERS
static FILE* open_file(char* file_name) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        perror("UNABLE TO OPEN FILE");
        return NULL;
    }

    return file;
}


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