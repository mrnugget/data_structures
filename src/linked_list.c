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

struct ll_node *LL_add(struct ll_node *head, void *val)
{
    struct ll_node *last = LL_last(head);
    struct ll_node *n = LL_new(val);
    check(n, "Could not allocate new node");

    last->next = n;

    return n;

error:
    return NULL;
}

struct ll_node *LL_last(struct ll_node *head)
{
    struct ll_node *last = head;
    while (last->next) {
        last = last->next;
    }
    return last;
}

int LL_length(struct ll_node *head)
{
    int i = 1;
    struct ll_node *curr = head;

    while (curr->next) {
        i++;
        curr = curr->next;
    }

    return i;
}

void LL_free(struct ll_node *head)
{
    struct ll_node *curr = head;
    struct ll_node *prev;

    while (curr->next) {
        prev = curr;
        curr = prev->next;
        free(prev);
        prev = NULL;
    }

    return;
}
