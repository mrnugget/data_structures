#ifndef _array_h
#define _array_h

struct dynarray {
    int length;
    void **elements;
    int capacity;
};

struct dynarray *Array_new(size_t initial_size);
void *Array_first(struct dynarray *a);
void *Array_last(struct dynarray *a);
int Array_expand(struct dynarray *a);
int Array_push(struct dynarray *a, void *el);
void *Array_pop(struct dynarray *a);
int Array_shift(struct dynarray *a, void *el);
void *Array_unshift(struct dynarray *a);
void Array_free(struct dynarray *a);
void benchmark_push_pop(int times, int init_size);

#endif
