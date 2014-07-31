#include <stdlib.h>

#include "debug.h"
#include "btree.h"

struct btree_node *Btree_new(void *val)
{
    struct btree_node *n = malloc(sizeof(struct btree_node));
    if (n == NULL) {
        return NULL;
    }

    n->val = val;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void Btree_free(struct btree_node *root)
{
    if (root->left) {
        Btree_free(root->left);
    }
    if (root->right) {
        Btree_free(root->right);
    }

    free(root);
}
