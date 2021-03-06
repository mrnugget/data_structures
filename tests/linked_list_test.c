#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_macros.h"
#include "linked_list.h"

struct ll_node *head;
char *val1 = "foobar";
char *val2 = "foobar2";
char *val3 = "foobar3";
char *val4 = "foobar4";

char *test_linked_list_new()
{
    head = LL_new(val1);

    test_assert(head, "Could not create new linked list");
    test_assert_streq(head->val, val1, "linked list head has wrong val");

    return NULL;
}

char *test_linked_list_add_tail()
{
    struct ll_node *n = LL_add_tail(head, val2);

    test_assert(n, "Could not create new node");
    test_assert_streq(n->val, val2, "linked list new node has wrong val");

    struct ll_node *n2 = LL_add_tail(head, val3);

    test_assert(n2, "Could not create new node");
    test_assert_streq(n2->val, val3, "linked list new node has wrong val");

    return NULL;
}

char *test_linked_list_last()
{
    struct ll_node *last = LL_last(head);

    test_assert(last, "Did not get last node");
    test_assert_streq(last->val, val3, "linked list last node has wrong val");

    return NULL;
}

char *test_linked_list_add_head()
{
    LL_add_head(&head, val4);
    test_assert_streq(head->val, val4, "linked list new head node has wrong val");

    return NULL;
}

char *test_linked_list_find()
{
    struct ll_node *found = LL_find(head, val2);

    test_assert(found, "Did not find node");
    test_assert_streq(found->val, val2, "linked list found node has wrong val");

    found = LL_find(head, "herpderp");
    test_assert(found == NULL, "Found wrong node");

    return NULL;
}

char *test_linked_list_length()
{
    int length = LL_length(head);
    test_assert(length == 4, "Did not get correct length");

    return NULL;
}

char *test_linked_list_delete()
{
    int length = LL_length(head);

    // Deleting the last node
    LL_delete(&head, val3);
    test_assert(LL_length(head) == (length - 1), "Wrong length after deletion");

    struct ll_node *last = LL_last(head);
    test_assert(last->val != val3, "linked list last node has wrong val after deletion");

    // Deleting the head node
    LL_delete(&head, val4);
    test_assert(LL_length(head) == (length - 2), "Wrong length after deletion");
    test_assert(head->val != val4, "linked list head node has wrong val after deletion");

    return NULL;
}

char *test_linked_list_free()
{
    LL_free(head);

    return NULL;
}

int main(int argc, char *argv[])
{
    printf("Running tests...\n");

    test_setup();

    run_test(test_linked_list_new);
    run_test(test_linked_list_add_tail);
    run_test(test_linked_list_last);
    run_test(test_linked_list_add_head);
    run_test(test_linked_list_find);
    run_test(test_linked_list_length);
    run_test(test_linked_list_delete);
    run_test(test_linked_list_free);

    printf("All tests passed.\n\n");

    return 0;
}
