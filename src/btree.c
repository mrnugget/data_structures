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
    // TODO: this is just for testing purposes here. we need to actually free
    // the whole tree
    free(root);
}
