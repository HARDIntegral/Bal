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

void march(list* list, void (*op)(node_l*), int reverse) {
    if (reverse!=0) {
        node_l* tmp = list->tail;
        while (tmp!=NULL) {
            tmp = tmp->prev;
            list->tail = tmp->next;
            op(list->tail);
        }
        return;
    }
    node_l* tmp = list->head;
    while (tmp!=NULL) {
        tmp = tmp->next;
        list->head = tmp->prev;
        op(list->head);
    }
}

void destroy_list(list* list) {
    march(list, &destroy_node, 0);
    list->head = NULL;
    list->tail = NULL;
    free(list);
    list=NULL;
}

int push(list* list, void* data, TYPES type) {
    node_l* node = generate_node(data, type);
    if (node == NULL)
        return FAILURE;
    
    if (list->head!=NULL)
        node->next = list->head;
    list->head = node;
    return SUCCESS;
}

int append(list* list, void* data, TYPES type) {
    node_l* node = generate_node(data, type);
    if (node == NULL)
        return FAILURE;
    
    if (list->tail!=NULL)
        node->prev = list->tail;
    list->tail = node;
    return SUCCESS;
}

return_vals* pop(list* list) {
    if (list==NULL || list->head==NULL)
        return NULL;
    return_vals* vals = (return_vals*) malloc(sizeof(return_vals));
    node_l* tmp = list->head;
    list->head = tmp->next;
    vals->data = tmp->data;
    vals->type = tmp->type;
    destroy_node(tmp);

    return vals;
}

return_vals* trim(list* list) {
    if (list==NULL || list->tail==NULL)
        return NULL;
    return_vals* vals = (return_vals*) malloc(sizeof(return_vals));
    node_l* tmp = list->tail;
    list->head = tmp->prev;
    vals->data = tmp->data;
    vals->type = tmp->type;
    destroy_node(tmp);

    return vals;
}