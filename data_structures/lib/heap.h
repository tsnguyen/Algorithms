/*=============================================================================
                The heap data structure

        Heap data structure using vector to store data. If we want to speed up,
        then use fixed length array instead.

        The indices will start from 1:
            the children of index i are (2 * i) and (2 * i + 1)
            the parent of index i is i/2 (round down)

=============================================================================*/

#ifndef __HEAP_H__
#define __HEAP_H__

#include "vector"

struct HeapElement{
	long key;
};

class Heap{
    private:
        std::vector< HeapElement > mHeapData;
    public:
        Heap(void);
        void BubbleUp(unsigned);     // Move the added element up the tree
        void BubbleDown(unsigned);   // Remove the root element by moving down
        void Add(HeapElement &);// Add one element to the heap
        HeapElement Pop(void); // Remove return the current min value
        HeapElement Min(void); // Return min value, the heap is unchanged
};

#endif
