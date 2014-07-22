#ifndef _linked_list_h
#define _linked_list_h

struct ll_node {
    void *val;
    void *next;
};

struct ll_node *LL_new();
void LL_free(struct ll_node *head);
struct ll_node *LL_add(struct ll_node *head, void *val);
struct ll_node *LL_last(struct ll_node *head);
int LL_length(struct ll_node *head);

#endif
