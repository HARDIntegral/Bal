#include "list.h"

static void destroy_node(node_l* node);
static node_l* generate_node(void* restrict data, COMMON_TYPES type);

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
    if (list == NULL) return;
    node_l* current = (reverse ? list->tail : list->head);

    while (current!=NULL) {
        (*op)(current);
        current =  (reverse ? (current->prev) : (current->next));
    }
}

void destroy_list(list* list) {
    march(list, &destroy_node, 0);
    list->head = NULL;
    list->tail = NULL;
    free(list);
    list=NULL;
}

int push(list* list, void* restrict data, COMMON_TYPES type) {
    node_l* node = generate_node(data, type);
    if (node == NULL) return FAILURE;
    
    if (list->size==0) list->tail = node;
    else {
        list->head->prev = node;
        node->next = list->head;
    }
    list->head = node;
    list->size++;
    return SUCCESS;
}

int append(list* list, void* restrict data, COMMON_TYPES type) {
    node_l* node = generate_node(data, type);
    if (node == NULL) return FAILURE;
    
    if (list->size==0)
        list->head = node;
    else {
        list->tail->next = node;
        node->prev = list->tail;
    }
    list->tail = node;
    list->size++;
    return SUCCESS;
}

static node_l* retrive_node(list* list, int pos);

return_vals* retrive_data(list* list, int pos, int destroy) {
    node_l* node = retrive_node(list, pos);
    if (node==NULL) return NULL;

    return_vals* val = (return_vals*)malloc(sizeof(return_vals));
    val->data = node->data;
    val->type = node->type;

    if (destroy!=0) destroy_node(node);

    return val;
}

return_vals* pop(list* list) {
    if (list==NULL || list->head==NULL) return NULL;
    return_vals* vals = retrive_data(list, 0, 1);
    return vals;
}

return_vals* trim(list* list) {
    if (list==NULL || list->tail==NULL) return NULL;
    return_vals* vals = retrive_data(list, list->size-1, 1);
    return vals;
}

int concat(list* a, list* b, int destroy_second) {
    if (a==NULL || b==NULL) return FAILURE;

    node_l* tmp = b->head;
    while (tmp!=NULL) {
        if (append(a, tmp->data, tmp->type)==FAILURE) return FAILURE;
        tmp = tmp->next;
    }
    if (destroy_second!=0) destroy_list(b);
    return SUCCESS;
}

// HELPERS
static void destroy_node(node_l* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;

    free(node->data);
    node->data = NULL;
    node->next = NULL;
    node->prev = NULL;
    
    free(node);
    node = NULL;
}

static node_l* generate_node(void* restrict data, COMMON_TYPES type) {
    node_l* new_node = (node_l*)malloc(sizeof(node_l));
    if (new_node!=NULL) {
        new_node->data = data;
        new_node->type = type;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    return new_node;
}

static node_l* retrive_node(list* list, int pos) {
    if (list==NULL || list->size<=pos) return NULL;
    
    node_l* tmp;
    int current_pos;
    int reverse;
    if (pos>(list->size-1)/2) {
        reverse = 1;
        current_pos = list->size-1;
        tmp = list->tail;
    } else {
        reverse = 0;
        current_pos = 0;
        tmp = list->head;
    }

    while (tmp!=NULL) {
        if (current_pos==pos)
            break;
        tmp = (reverse ? (tmp->prev) : (tmp->next));
        current_pos = (reverse ? current_pos-- : current_pos++);
    }

    return tmp;
}