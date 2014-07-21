#include <stdlib.h>

#include "debug.h"
#include "linked_list.h"

struct ll_node *LL_new(void *val)
{
    struct ll_node *n = malloc(sizeof(struct ll_node));
    check(n, "Could not allocate linked list\n");

    n->val = val;
    n->next = NULL;

    return n;

error:
    if (n) free(n);
    return NULL;
}

void LL_free(struct ll_node *head)
{
    free(head);
    head = NULL;
}
