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
typedef struct return_vals return_vals;
struct return_vals {
    void* data;
    TYPES type;
};

list* generate_list();
void destroy_list(list* list);

void march(list* list, void (*op)(node_l*), int reverse);
void destroy_node(node_l* node);

int push(list* list, void* data, TYPES type);
int append(list* list, void* data, TYPES type);
return_vals* pop(list* list);
return_vals* trim(list* list);

#endif // LIST_H