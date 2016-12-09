#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

struct stack *Stack_new()
{
    struct stack *s = malloc(sizeof(struct stack));
    if (s == NULL) {
        return NULL;
    }

    s->top = s->elements;
    s->sp = 0;

    return s;
}

int Stack_push(struct stack *s, void *el)
{
    *s->top = el;
    s->top++;
    return 0;
}

void *Stack_pop(struct stack *s)
{
    void *el = *(--s->top);
    return el;
}

void Stack_free(struct stack *s)
{
    free(s);
}
