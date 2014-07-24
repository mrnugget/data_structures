#ifndef _linked_list_h
#define _linked_list_h

struct ll_node {
    void *val;
    void *next;
};

struct ll_node *LL_new();
void LL_free(struct ll_node *head);
struct ll_node *LL_add_tail(struct ll_node *head, void *val);
void LL_add_head(struct ll_node **head, void *val);
struct ll_node *LL_last(struct ll_node *head);
struct ll_node *LL_find(struct ll_node *head, void *val);
int LL_length(struct ll_node *head);

#endif
