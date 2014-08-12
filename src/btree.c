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

struct btree_node *Btree_new(void *key, void *val)
{
    struct btree_node *n = malloc(sizeof(struct btree_node));
    if (n == NULL) {
        return NULL;
    }

    n->key = key;
    n->val = val;
    n->left = NULL;
    n->right = NULL;

    return n;
}

struct btree_node *Btree_insert(struct btree_node *root, void *key, void *val)
{
    struct btree_node *new = Btree_new(key, val);
    if (new == NULL) {
        return NULL;
    }

    Btree_add_node(root, new);

    return new;
}

struct btree_node *Btree_find(struct btree_node *root, void *key)
{
    int cmp = BTREE_DEFAULT_COMPARE(root->key, key);
    struct btree_node *result = NULL;

    if (cmp == 0) return root;
    if (cmp == 1 && root->left) return Btree_find(root->left, key);
    if (cmp == -1 && root->right) return Btree_find(root->right, key);

    return result;
}

int Btree_count(struct btree_node *node)
{
    int c = 0;

    if (node) c++;
    if (node->left) c += Btree_count(node->left);
    if (node->right) c += Btree_count(node->right);

    return c;
}

static void Btree_add_node(struct btree_node *root, struct btree_node *new)
{
    int cmp = BTREE_DEFAULT_COMPARE(root->key, new->key);
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
