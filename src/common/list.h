#ifndef LIST_H
#define LIST_H

#include "common_header.h"

typedef struct node_l node_l;
struct node_l {
    void* data;
    node_l* next;
    node_l* prev;
};
typedef struct list list;
struct list {
    node_l* head;
    node_l* tail;
    int size;
    COMMON_TYPES type;
};

list* generate_list(COMMON_TYPES type);
void destroy_list(list* list);
void destroy_node(node_l* node);

void march(list* list, void (*op)(node_l*), int reverse);

int push(list* list, void* restrict data);
int append(list* list, void* restrict data);
return_vals* retrive_data(list* list, int pos, int destroy);
node_l* pop(list* list);
node_l* trim(list* list);
int concat(list* a, list* b, int destroy_second);

#endif // LIST_H