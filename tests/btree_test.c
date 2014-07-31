#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_macros.h"
#include "btree.h"

struct btree_node *root;
int val1 = 5;

char *test_btree_new()
{
    root = Btree_new(&val1);

    test_assert(root, "root node not created");

    test_assert(*(int *)root->val == 5, "root val is not correct");
    test_assert(root->left == NULL, "root val left is set");
    test_assert(root->right == NULL, "root val right is set");

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
    run_test(test_btree_free);

    printf("All tests passed.\n\n");

    return 0;
}
