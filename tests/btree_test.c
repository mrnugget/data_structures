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
int val4 = 1;
int val5 = 15;

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
    // Inserting a value that is smaller than root's value
    struct btree_node *left = Btree_insert(root, &val2);

    test_assert(root->left, "root left node is NULL");
    test_assert(*(int *)root->left->val == val2, "left leaf of root has wrong value");

    test_assert(*(int *)left->val == val2, "left node has wrong value");
    test_assert(left->left == NULL, "left node has left set");
    test_assert(left->right == NULL, "left node has right set");

    // Inserting a value that is greater than root's value
    struct btree_node *right = Btree_insert(root, &val3);

    test_assert(root->right, "root left node is NULL");
    test_assert(*(int *)root->right->val == val3, "left leaf of root has wrong value");

    test_assert(*(int *)right->val == val3, "right node has wrong value");
    test_assert(right->left == NULL, "right node has left set");
    test_assert(right->right == NULL, "right node has right set");

    // Inserting a value that is smaller than root's left node
    struct btree_node *left2 = Btree_insert(root, &val4);

    test_assert(left->left, "first-level left node's left is NULL");
    test_assert(*(int *)left->left->val == val4, "left leaf of first-level left has wrong value");

    test_assert(*(int *)left2->val == val4, "right node has wrong value");
    test_assert(left2->left == NULL, "right node has left set");
    test_assert(left2->right == NULL, "right node has right set");

    // Inserting a value that is greater than root's right node
    struct btree_node *right2 = Btree_insert(root, &val5);

    test_assert(right->right, "first-level left node's left is NULL");
    test_assert(*(int *)right->right->val == val5, "left leaf of first-level left has wrong value");

    test_assert(*(int *)right2->val == val5, "right node has wrong value");
    test_assert(right2->left == NULL, "right node has left set");
    test_assert(right2->right == NULL, "right node has right set");

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
