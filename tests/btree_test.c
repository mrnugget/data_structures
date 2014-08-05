#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_macros.h"
#include "btree.h"

struct btree_node *root;

int val1 = 5;
int val2 = 3;
int val3 = 10;

char *test_btree_new()
{
    root = Btree_new(&val1);

    test_assert(root, "root node not created");

    test_assert(*(int *)root->val == 5, "root val is not correct");
    test_assert(root->left == NULL, "root val left is set");
    test_assert(root->right == NULL, "root val right is set");

    return NULL;
}

char *test_btree_insert()
{
    struct btree_node *new = Btree_insert(root, &val2);

    test_assert(*(int *)new->val == 3, "new node has wrong value");
    test_assert(new->left == NULL, "new node has left set");
    test_assert(new->right == NULL, "new node has right set");

    test_assert(*(int *)root->left->val == 3, "left leaf of root has wrong value");

    new = Btree_insert(root, &val3);

    test_assert(*(int *)new->val == 10, "new node has wrong value");
    test_assert(new->left == NULL, "new node has left set");
    test_assert(new->right == NULL, "new node has right set");

    test_assert(*(int *)root->right->val == 10, "left leaf of root has wrong value");

    return NULL;
}

char *test_btree_free()
{
    Btree_free(root);

    return NULL;
}

int main(int argc, char *argv[])
{
    printf("Running tests...\n");

    test_setup();

    run_test(test_btree_new);
    run_test(test_btree_insert);
    run_test(test_btree_free);

    printf("All tests passed.\n\n");

    return 0;
}
