#include "hash.h"

ht* generate_table(uint8_t init_size) {
    return (hash*)malloc(init_size*sizeof(hash));
}

hash* generate_hash(ht* hash_table, void* data, COMMON_TYPES type) {
    hash* new_hash = (hash*)malloc(sizeof(hash));
    if (new_hash)
        new_hash->data = data;
        new_hash->type = type;

    // generate hash code
    // read bytes and do some fancy math I guess

    return new_hash;
}

int attach_hash(ht* hash_table, hash* data_hash) {
    // gotta figure out how to deal with same hash values 
    // maybe a dangling list or something like that...


}