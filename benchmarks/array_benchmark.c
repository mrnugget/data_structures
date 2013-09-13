#include <stdio.h>

#include "array.h"
#include "benchmark_macros.h"

void benchmark_push_pop(int times, int init_size)
{
    int i;
    struct dynarray *a = Array_new(init_size);

    for (i = 0; i < times; i++) {
        Array_push(a, &i);
    }

    for (i = times; i > 0; i--) {
        Array_pop(a);
    }
    Array_free(a);
}

int main(int argc, char *argv[])
{
    printf("Running benchmarks...\n");
    benchmark_setup();

    run_benchmark(benchmark_push_pop,
            "Pushing 1000000 elements and popping them, init = 100", 1000000, 100);

    printf("All benchmarks run.\n");

    return 0;
}
