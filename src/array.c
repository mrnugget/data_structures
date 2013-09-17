#include <stdlib.h>

#include "debug.h"
#include "array.h"

struct dynarray *Array_new(size_t initial_size)
{
    struct dynarray *a = malloc(sizeof(struct dynarray));
    check(a, "Could not allocate array\n");

    a->elements = malloc(initial_size * sizeof(void *));
    check(a->elements, "Could not allocate elements\n");

    a->capacity = initial_size;
    a->length = 0;

    return a;

error:
    if (a) free(a);
    return NULL;
}

void *Array_first(struct dynarray *a)
{
    return a->elements[0];
}

void *Array_last(struct dynarray *a)
{
    return a->elements[a->length-1];
}

int Array_expand(struct dynarray *a)
{
    int capacity = a->capacity * 2;
    void *elements = realloc(a->elements, (sizeof(void *) * capacity));
    check(elements, "Could not expand elements size\n");

    a->capacity = capacity;
    a->elements = elements;

    return 0;
error:
    return -1;
}

int Array_shift(struct dynarray *a, void *el)
{
    int i;

    if ((a->length + 1) >= a->capacity) {
        check(Array_expand(a) == 0, "Could not expand Array");
    }

    for (i = a->length; i < 0; i--) {
        a->elements[i + 1] = a->elements[i];
    }

    a->elements[0] = el;
    a->length++;

    return 0;
error:
    return -1;
}

int Array_push(struct dynarray *a, void *el)
{
    if ((a->length + 1) >= a->capacity) {
        check(Array_expand(a) == 0, "Could not expand Array");
    }

    a->elements[a->length++] = el;

    return 0;
error:
    return -1;
}

void *Array_pop(struct dynarray *a)
{
    return a->elements[--a->length];
}

void Array_free(struct dynarray *a)
{
    if (a) {
        if (a->elements) {
            free(a->elements);
        }
        free(a);
    }
}
