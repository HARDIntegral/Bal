#ifndef LIST_H
#define LIST_H

#include "common_header.h"

typedef struct node_l node_l;
struct node_l {
    void* data;
    TYPES type;
    node_l* next;
    node_l* prev;
};
typedef struct list list;
struct list {
    node_l* head;
    node_l* tail;
    int size;
};

list* generate_list();
void destroy_list(list* list);

void forward_march(list* list, void (*op)(node_l*));
void backward_march(list* list, void (*op)(node_l*));
void destroy_node(node_l* node);

#endif // LIST_H