OBJECTS=src/array.o src/linked_list.o

CFLAGS=-g -Wall -O3 -I ./src
LDLIBS=
CC=gcc

# TESTS
array_test: ./tests/array_test.c $(OBJECTS)
	$(CC) $(CFLAGS) -o ./tests/$@ $(OBJECTS) ./tests/$@.c

linked_list_test: ./tests/linked_list_test.c $(OBJECTS)
	$(CC) $(CFLAGS) -o ./tests/$@ $(OBJECTS) ./tests/$@.c

test: array_test linked_list_test

# BENCHMARKS
array_benchmark: $(OBJECTS)
	$(CC) $(CFLAGS) -o ./benchmarks/$@ $(OBJECTS) ./benchmarks/$@.c

benchmark: array_benchmark

clean:
	rm -rf ./tests/array_test ./tests/linked_list_test ./benchmarks/array_benchmark $(OBJECTS)
	find . -name "*.dSYM" -print | xargs rm -rf
