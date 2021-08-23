#include "hash.h"

table* generate_table() {
    table* new_table = (table*)malloc(sizeof(table));
    if (new_table!=NULL) {
        new_table->hashes = NULL;
        new_table->size = 1;
    }
    return new_table;
}

int resize_table(table* hash_table) {
    if (hash_table==NULL) return FAILURE;
    hash_table = (table*)realloc(hash_table, hash_table->size*2*sizeof(table));
}

unsigned int generate_hash(void* data, TYPES type) {
    hash* new_hash = (hash*)malloc(sizeof(hash));
    if (new_hash==NULL) return FAILURE;
    new_hash->data = data;
    new_hash->type = type;

    // generate hash code
    // TODO: add support for other types as well
    if (type==STRING) {
        // TODO: create hash function for strings
    } else if (type==INTEGER) {
        // TODO: create hash function for ints
    } else return FAILURE;
    return SUCCESS;
}

// TODO: implement this function
int attach_hash(table* hash_table, hash* data_hash) {
    return FAILURE;
}