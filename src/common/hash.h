#ifndef HASH_H
#define HASH_H

#include <stdint.h>
#include <math.h>
#include <string.h>
#include "common_header.h"

typedef struct ht {
    hash* hashes;
    uint8_t size;
}ht;
typedef struct hash {
    uint16_t hash;
    void* data;
    COMMON_TYPES type;
}hash;

ht* generate_table(uint8_t init_size);
hash* generate_hash(ht* hash_table, void* data, COMMON_TYPES type);
int attach_hash(ht* hash_table, hash* data_hash);

#endif // HASH_H