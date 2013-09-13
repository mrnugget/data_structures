#ifndef _benchmark_macros_h
#define _benchmark_macros_h

#include <time.h>
#include <unistd.h>

#define benchmark_setup() clock_t be_start, be_end;
#define run_benchmark(B, M, ...) printf("  "M"\n");\
    be_start = clock();\
    B(__VA_ARGS__);\
    be_end = clock();\
    printf("    Time elapsed: %fsec\n", (double)(be_end - be_start) / CLOCKS_PER_SEC);

#endif
