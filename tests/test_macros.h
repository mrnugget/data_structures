#ifndef _test_macros_h
#define _test_macros_h

#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define NORMAL "\x1B[0m"

#define test_assert_streq(A, B, M) test_assert(strcmp((char *)A, (char *)B) == 0, M);
#define test_assert(A, B) if(!(A)) { return B; }

#define test_setup() char *test_error_message = NULL;
#define run_test(T) printf("  %s: ", " " #T);\
    test_error_message = T();\
    if (test_error_message) { printf(RED"FAIL: %s\n"NORMAL, test_error_message); return -1; }\
    else { printf(GREEN"OK!\n"NORMAL); }

#endif
