#ifndef _linked_list_h
#define _linked_list_h

struct ll_node {
    void *val;
    void *next;
};

struct ll_node *LL_new();
void LL_free(struct ll_node *head);

#endif
