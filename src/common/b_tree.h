#ifndef B_TREE_H
#define B_TREE_H

#include "common_header.h"

typedef struct node_b node_b;
struct node_b {
    void* data;
    COMMON_TYPES type;
    node_b* left;
    node_b* right;
};
typedef struct tree tree;
struct tree {
    node_b* root;
};

tree* generate_tree();
void destroy_tree(tree* tree);

void traverse();

#endif // B_TREE_H