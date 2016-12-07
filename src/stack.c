#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

#define INITIAL_SIZE 300

struct stack *Stack_new()
{
    struct stack *s = malloc(sizeof(struct stack));
    if (s == NULL) {
        return NULL;
    }

    void **elements = malloc(sizeof(void*)*INITIAL_SIZE);
    if (elements == NULL) {
        free(s);
        return NULL;
    }

    s->elements = elements;
    s->sp = 0;

    return s;
}

int Stack_push(struct stack *s, void *el)
{
    s->elements[s->sp++] = el;

    return 0;
}

void *Stack_pop(struct stack *s)
{
    void *el = s->elements[s->sp-1];
    s->sp--;
    return el;
}

void Stack_free(struct stack *s)
{
    free(s->elements);
    free(s);
}
