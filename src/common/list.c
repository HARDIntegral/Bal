#include "list.h"

void destroy_node(node_l* node) {
    free(node->data);
    node->data = NULL;
    node->next = NULL;
    node->prev = NULL;
    
    free(node);
    node = NULL;
}

node_l* generate_node(void* data, TYPES type) {
    node_l* new_node = (node_l*)malloc(sizeof(node_l));
    if (new_node!=NULL) {
        new_node->data = data;
        new_node->type = type;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    return new_node;
}

list* generate_list() {
    list* new_list = (list*)malloc(sizeof(list));
    if (new_list!=NULL) {
        new_list->head = NULL;
        new_list->tail = NULL;
        new_list->size = 0;
    }
    return new_list;
}

void forward_march(list* list, void (*op)(node_l*)) {
    node_l* tmp = list->head;
    while (tmp!=NULL) {
        tmp = tmp->next;
        list->head = tmp->prev;
        op(list->head);
    }
}

void reverse_march(list* list, void (*op)(node_l*)) {
    node_l* tmp = list->tail;
    while (tmp!=NULL) {
        tmp = tmp->prev;
        list->tail = tmp->next;
        op(list->tail);
    }
}