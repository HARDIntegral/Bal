#ifndef LIST_H
#define LIST_H

#include "common_header.h"

typedef struct node_l node_l;
typedef struct list list;

list* generate_list();
void destroy_list(list* list);

#endif // LIST_H