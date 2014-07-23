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

struct ll_node *LL_add_tail(struct ll_node *head, void *val)
{
    struct ll_node *last = LL_last(head);
    struct ll_node *n = LL_new(val);
    check(n, "Could not allocate new node");

    last->next = n;

    return n;

error:
    return NULL;
}

void LL_add_head(struct ll_node **headp, void *val)
{
    struct ll_node *n = LL_new(val);
    if (n == NULL) return;

    n->next = *headp;
    *headp = n;
    return;
}

struct ll_node *LL_last(struct ll_node *head)
{
    while (head->next) {
        head = head->next;
    }
    return head;
}

int LL_length(struct ll_node *head)
{
    int i = 1;

    while (head->next) {
        i++;
        head = head->next;
    }

    return i;
}

void LL_free(struct ll_node *head)
{
    struct ll_node *prev;

    while (head->next) {
        prev = head;
        head = prev->next;
        free(prev);
        prev = NULL;
    }

    return;
}
