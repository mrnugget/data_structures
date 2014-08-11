# Data Structures in C

My data structures playground in which I implement some common data structures
in C.

## Currently Implemented

* Dynamic Array
* Linked List
* BTree

## Compiling with tests

`make`

## Running the tests

`make clean && make test && ./tests/array_test`
`make clean && make test && ./tests/linked_list_test`
`make clean && make test && ./tests/btree_test`

## Running the benchmarks

`make clean && make benchmark && ./benchmarks/array_benchmark`

## Credit

A lot of this, especially the debug and test macros and the DArray
implementation, is inspired by Zed Shaw's Learn C The Hard Way. Thanks!

## License

MIT. Do what you want with this.
