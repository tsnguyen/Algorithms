Sorting algorithms
===============================================================================

These sorting algorithms are implemented for intergers for now. Later I will
rewrite them using template. Actually there is one sorting function in the
[vector utilities header file][my_vector_utilities] that implemented merge sort
using template already.

All the sort classes are having the same interface, but the implementation 
details can be different (such as the data structure that stores the list). I
am planning to have the following sorting agorithms implemented

1. Selection sort
2. Merge sort
3. Quick sort
4. Heap sort

The [test file][test_sot] generates a list of random integers and sort the list
using different algorithms.

[my_vector_utilities]: lib/my_vector_utilities.h
[test_sort]: test/test_sort.cpp