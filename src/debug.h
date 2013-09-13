#ifndef _debug_h
#define _debug_h

#include <stdio.h>

#define check(A, B, ...) if(!(A)) { fprintf(stderr, B, ##__VA_ARGS__); goto error; }

#endif
