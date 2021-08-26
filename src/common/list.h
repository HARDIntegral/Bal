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
    unsigned int size;
};

list* generate_list();
void destroy_list(list* list);

void march(list* list, void (*op)(node_l*), int reverse);
void destroy_node(node_l* node);

int push(list* list, void* data, TYPES type);
int append(list* list, void* data, TYPES type);
return_vals* retrive_data(list* list, int pos, int destroy);
return_vals* pop(list* list);
return_vals* trim(list* list);
int concat(list* a, list* b, int destroy_second);

#endif // LIST_H