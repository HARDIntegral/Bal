#include "b_tree.h"

tree* generate_tree() {
    tree* new_tree = (tree*) malloc(sizeof(tree));
    if (new_tree!=NULL)
        new_tree->root = NULL;
    return new_tree;
}

void destroy_tree(tree* tree) {
    //traverse the tree and destroy all nodes somehow
    free(tree->root);
    free(tree);
    tree->root = NULL;
    tree = NULL;
}