#include "hash.h"

ht* generate_table(uint8_t init_size) {
    return (hash*)malloc(init_size*sizeof(hash));
}

hash* generate_hash(ht* hash_table, void* data, COMMON_TYPES type) {
    hash* new_hash = (hash*)malloc(sizeof(hash));
    if (new_hash) {
        new_hash->data = data;
        new_hash->type = type;

        // I have no idea if this even works yet
        // gonna be a problem for future integral
        uint16_t hash_code = 0;
        for (uint8_t i = 0; i < (uint8_t)type; i++) 
            hash_code += (uint16_t)exp(((char*)data)[i]) % hash_table->size;
        hash_code %= hash_table->size;
    }
    return new_hash;
}

void attach_hash(ht* hash_table, hash* data_hash) {
    if (hash_table->hashes[data_hash->hash]) {    
        // gotta figure out how to deal with same hash values 
        // maybe a dangling list or something like that...
        return;
    }
    hash_table->hashes[data_hash->hash] = data_hash; 
}