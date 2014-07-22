#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_macros.h"
#include "array.h"

#define TEST_INIT_SIZE 200

struct dynarray *a;
char *one = "ONE";
char *two = "TWO";
char *three = "THREE";

char *test_array_new()
{
    a = Array_new(TEST_INIT_SIZE);
    test_assert(a != NULL, "Could not create new array\n");

    return NULL;
}

char *test_array_push()
{
    test_assert(Array_push(a, one) == 0, "Push one failed");
    test_assert(Array_push(a, two) == 0, "Push two failed");
    test_assert(Array_push(a, three) == 0, "Push three failed");

    test_assert(a->length == 3, "Wrong length after push");

    test_assert_streq(a->elements[0], one, "Wrong element: one");
    test_assert_streq(a->elements[1], two, "Wrong element: two");
    test_assert_streq(a->elements[2], three, "Wrong element: three");

    return NULL;
}

char *test_array_first()
{
    test_assert_streq(Array_first(a), one, "First element is wrong");

    return NULL;
}

char *test_array_last()
{
    test_assert_streq(Array_last(a), three, "Last element is wrong");

    return NULL;
}

char *test_array_pop()
{
    char *popped = Array_pop(a);
    test_assert(a->length == 2, "Array length is not 2");
    test_assert_streq(popped, three, "Wrong popped element: three");

    popped = Array_pop(a);
    test_assert(a->length == 1, "Array length is not 1");
    test_assert_streq(popped, two, "Wrong popped element: two");

    popped = Array_pop(a);
    test_assert(a->length == 0, "Array length is not 0");
    test_assert_streq(popped, one, "Wrong popped element: one");

    return NULL;
}

char *test_array_shift()
{
    test_assert(a->length == 0, "Array is not empty");

    Array_shift(a, one);
    test_assert(a->length == 1, "Array length is not 1");
    test_assert_streq(Array_first(a), one, "Wrong first element: one");

    Array_shift(a, two);
    test_assert(a->length == 2, "Array length is not 2");
    test_assert_streq(Array_first(a), two, "Wrong second element: two");

    Array_shift(a, three);
    test_assert(a->length == 3, "Array length is not 3");
    test_assert_streq(Array_first(a), three, "Wrong second element: three");

    test_assert_streq(a->elements[0], three, "Wrong element: three");
    test_assert_streq(a->elements[1], two, "Wrong element: two");
    test_assert_streq(a->elements[2], one, "Wrong element: one");

    return NULL;
}

char *test_array_unshift()
{
    char *unshifted = Array_unshift(a);
    test_assert(a->length == 2, "Array length is not 2");
    test_assert_streq(unshifted, three, "Wrong unshifted element: three");

    unshifted = Array_unshift(a);
    test_assert(a->length == 1, "Array length is not 1");
    test_assert_streq(unshifted, two, "Wrong unshifted element: two");

    unshifted = Array_unshift(a);
    test_assert(a->length == 0, "Array length is not 0");
    test_assert_streq(unshifted, one, "Wrong unshifted element: one");

    return NULL;
}

char *test_array_free()
{
    Array_free(a);

    return NULL;
}

int main(int argc, char *argv[])
{
    printf("Running tests...\n");

    test_setup();

    run_test(test_array_new);
    run_test(test_array_push);
    run_test(test_array_first);
    run_test(test_array_last);
    run_test(test_array_pop);
    run_test(test_array_shift);
    run_test(test_array_unshift);
    run_test(test_array_free);

    printf("All tests passed.\n\n");

    return 0;
}
