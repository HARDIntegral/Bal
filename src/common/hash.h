#ifndef HASH_H
#define HASH_H

#include <math.h>
#include <string.h>
#include "list.h"

typedef struct table table; 
struct table {
    list* hashes; 
    unsigned int size;
};
typedef struct hash hash;
struct hash {
    void* data;
    TYPES type;
    unsigned int pos;
};

table* generate_table(int init_size);
int resize_table(table* hash_table);
hash* generate_hash(void* data, TYPES type);
int attach_hash(table* hash_table, hash* data_hash);

#endif // HASH_H