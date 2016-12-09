#ifndef _stack_h_
#define _stack_h_

#define INITIAL_STACK_SIZE 300

struct stack {
  int sp;
  void **top;
  void *elements[INITIAL_STACK_SIZE];
};

struct stack *Stack_new();
int Stack_push(struct stack *s, void *el);
void *Stack_pop(struct stack *s);

#endif
