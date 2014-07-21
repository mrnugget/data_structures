#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_macros.h"
#include "linked_list.h"

#define test_assert_streq(A, B, M) test_assert(strcmp((char *)A, (char *)B) == 0, M);

struct ll_node *head;
char *val1 = "foobar";

char *test_linked_list_new()
{
    head = LL_new(val1);

    test_assert(head != NULL, "Could not create new linked list\n");
    test_assert_streq(head->val, val1, "linked list head has wrong val");

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
    run_test(test_linked_list_free);

    printf("All tests passed.\n\n");

    return 0;
}
