#ifndef _btree_h
#define _btree_h

struct btree_node {
  struct btree_node *left;
  struct btree_node *right;
  void *val;
};

struct btree_node *Btree_new(void *val);
void Btree_free(struct btree_node *root);

#endif
