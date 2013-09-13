OBJECTS=src/array.o
CFLAGS=-g -Wall -O3 -I ./src
LDLIBS=
CC=gcc

TESTS=tests/array_test

$(TESTS): $(OBJECTS)
test: $(TESTS)

BENCHMARKS=benchmarks/array_benchmark

$(BENCHMARKS): $(OBJECTS)
benchmark: $(BENCHMARKS)

clean:
	rm -rf $(TESTS) $(BENCHMARKS) $(OBJECTS)
	find . -name "*.dSYM" -print | xargs rm -rf
