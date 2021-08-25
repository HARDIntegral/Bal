#include "hash.h"

table* generate_table(int init_size) {
    table* new_table = (table*)malloc(init_size * sizeof(table));
    if (new_table!=NULL) {
        new_table->hashes = NULL;
        new_table->size = init_size;
    }
    return new_table;
}

int resize_table(table* hash_table) {
    if (hash_table==NULL) return FAILURE;
    hash_table = (table*)realloc(hash_table, hash_table->size*2*sizeof(table));
}

hash* generate_hash(table* hash_table, void* data, TYPES type) {
    hash* new_hash = (hash*)malloc(sizeof(hash));
    if (new_hash==NULL) return FAILURE;
    new_hash->data = data;
    new_hash->type = type;

    // generate hash code
    int table_size = hash_table->size;
    switch (type) {
        case INTEGER:
            int tmp = *(int*)data;
            if (tmp<0) tmp *= -1;
            new_hash->pos = (int)exp(tmp) % table_size;
            break;
        case DOUBLE:
            double tmp = *(double*)data;
            if (tmp<0) tmp *= -1;
            new_hash->pos = (int)exp(tmp) % table_size;
            break;
        case STRING:
            int tmp = 0;
            int str_len = strlen((char*)data);
            for (int i=0; i<str_len; i++)
                tmp += *((char*)data + i);
            new_hash->pos = (int)exp(tmp) % table_size;
            break;
        default:
            return NULL;
    }

    return new_hash;
}

// TODO: implement this function
int attach_hash(table* hash_table, hash* data_hash) {
    return FAILURE;
}