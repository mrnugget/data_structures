#include <stdlib.h>

#include "debug.h"
#include "btree.h"

#define BTREE_DEFAULT_COMPARE btree_compare_int

static void Btree_add_node(struct btree_node *root, struct btree_node *n);

int btree_compare_int(int *a, int *b)
{
    if (*a > *b) {
        return 1;
    } else if (*a < *b) {
        return -1;
    }

    return 0;
}

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

struct btree_node *Btree_insert(struct btree_node *root, void *val)
{
    struct btree_node *new = Btree_new(val);
    if (new == NULL) {
        return NULL;
    }

    Btree_add_node(root, new);

    return new;
}

static void Btree_add_node(struct btree_node *root, struct btree_node *new)
{
    int cmp = BTREE_DEFAULT_COMPARE(root->val, new->val);
    if (cmp == 1) {
        if (root->left) {
            Btree_add_node(root->left, new);
        } else {
            root->left = new;
        }
    } else if (cmp == -1) {
        if (root->right) {
            Btree_add_node(root->right, new);
        } else {
            root->right = new;
        }
    }
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
