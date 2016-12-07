#ifndef _stack_h_
#define _stack_h_

struct stack {
  int sp;
  void **elements;
};

struct stack *Stack_new();
int Stack_push(struct stack *s, void *el);
void *Stack_pop(struct stack *s);

#endif
