#include "list.h"

struct node_l {
    void* data;
    TYPES type;
    node_l* next;
    node_l* prev;
};

struct list {
    node_l* head;
    node_l* tail;
    int size;
}

node_l* generate_node(void* data, TYPES type) {
    
}