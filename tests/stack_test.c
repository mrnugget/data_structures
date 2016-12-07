#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_macros.h"
#include "stack.h"

struct stack *s;
char *one = "ONE";
char *two = "TWO";
char *three = "THREE";

char *test_stack_new()
{
    s = Stack_new();
    test_assert(s != NULL, "Could not create new stack\n");

    return NULL;
}

char *test_stack_push()
{
    test_assert(Stack_push(s, one) == 0, "Push one failed");
    test_assert(Stack_push(s, two) == 0, "Push two failed");
    test_assert(Stack_push(s, three) == 0, "Push three failed");

    test_assert_streq(s->elements[0], one, "Wrong element: one");
    test_assert_streq(s->elements[1], two, "Wrong element: two");
    test_assert_streq(s->elements[2], three, "Wrong element: three");

    return NULL;
}

char *test_stack_pop()
{
    char *popped = Stack_pop(s);
    test_assert_streq(popped, three, "Wrong popped element: three");

    popped = Stack_pop(s);
    test_assert_streq(popped, two, "Wrong popped element: two");

    popped = Stack_pop(s);
    test_assert_streq(popped, one, "Wrong popped element: one");

    return NULL;
}

int main(int argc, char *argv[])
{
    printf("Running tests...\n");

    test_setup();

    run_test(test_stack_new);
    run_test(test_stack_push);
    run_test(test_stack_pop);

    printf("All tests passed.\n\n");

    return 0;
}
