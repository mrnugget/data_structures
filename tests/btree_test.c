#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_macros.h"
#include "btree.h"

struct btree_node *root;

int key1 = 5;
char *val1 = "Welcome to Jurassic Park!";

int key2 = 3;
char *val2 = "Hold on to your butts";

int key3 = 10;
char *val3 = "This is a UNIX system!";

int key4 = 1;
char *val4 = "I know this!";

int key5 = 15;
char *val5 = "I hate this hacker crap";

char *test_btree_new()
{
    root = Btree_new(&key1, val1);

    test_assert(root, "root node not created");

    test_assert(*(int *)root->key == 5, "root val is not correct");
    test_assert(root->left == NULL, "root val left is set");
    test_assert(root->right == NULL, "root val right is set");

    return NULL;
}

char *test_btree_insert()
{
    // Inserting a value that is smaller than root's value
    struct btree_node *left = Btree_insert(root, &key2, val2);

    test_assert(root->left, "root left node is NULL");
    test_assert(*(int *)root->left->key == key2, "left leaf of root has wrong key");
    test_assert_streq(root->left->val, val2, "left leaf of root has wrong value");

    test_assert(*(int *)left->key == key2, "left node has wrong key");
    test_assert_streq(left->val, val2, "left leaf of root has wrong value");
    test_assert(left->left == NULL, "left node has left set");
    test_assert(left->right == NULL, "left node has right set");

    // Inserting a key that is greater than root's key
    struct btree_node *right = Btree_insert(root, &key3, val3);

    test_assert(root->right, "root left node is NULL");
    test_assert(*(int *)root->right->key == key3, "left leaf of root has wrong key");
    test_assert_streq(root->right->val, val3, "right leaf of root has wrong value");

    test_assert(*(int *)right->key == key3, "right node has wrong key");
    test_assert_streq(right->val, val3, "right leaf of root has wrong value");
    test_assert(right->left == NULL, "right node has left set");
    test_assert(right->right == NULL, "right node has right set");

    // Inserting a key that is smaller than root's left node
    struct btree_node *left2 = Btree_insert(root, &key4, val4);

    test_assert(left->left, "first-level left node's left is NULL");
    test_assert(*(int *)left->left->key == key4, "left leaf of first-level left has wrong key");
    test_assert_streq(left->left->val, val4, "left leaf of first-level left has wrong value");

    test_assert(*(int *)left2->key == key4, "right node has wrong key");
    test_assert_streq(left2->val, val4, "left leaf of first-level left has wrong value");
    test_assert(left2->left == NULL, "right node has left set");
    test_assert(left2->right == NULL, "right node has right set");

    // Inserting a key that is greater than root's right node
    struct btree_node *right2 = Btree_insert(root, &key5, val5);

    test_assert(right->right, "first-level right node's right is NULL");
    test_assert(*(int *)right->right->key == key5, "right leaf of first-level right node has wrong key");
    test_assert_streq(right->right->val, val5, "right leaf of first-level right node has wrong key");

    test_assert(*(int *)right2->key == key5, "right leaf of first-level right node has wrong key");
    test_assert_streq(right2->val, val5, "right leaf of first-level right node has wrong value");
    test_assert(right2->left == NULL, "right node has left set");
    test_assert(right2->right == NULL, "right node has right set");

    return NULL;
}

char *test_btree_count()
{
    test_assert(Btree_count(root) == 5, "count is wrong");

    return NULL;
}

char *test_btree_find()
{
    struct btree_node *result;

    result = Btree_find(root, &key5);
    test_assert_streq(result->val, val5, "node with key5 is not correct");

    result = Btree_find(root, &key4);
    test_assert_streq(result->val, val4, "node with key4 is not correct");

    result = Btree_find(root, &key3);
    test_assert_streq(result->val, val3, "node with key3 is not correct");

    result = Btree_find(root, &key2);
    test_assert_streq(result->val, val2, "node with key2 is not correct");

    result = Btree_find(root, &key1);
    test_assert_streq(result->val, val1, "node with key1 is not correct");

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
    run_test(test_btree_count);
    run_test(test_btree_find);
    run_test(test_btree_free);

    printf("All tests passed.\n\n");

    return 0;
}
