/*=============================================================================
                The heap data structure, specifically for graphs

        Heap data structure using vector to store data. If we want to speed up,
        then use fixed length array instead.

        The indices will start from 1:
            the children of index i are (2 * i) and (2 * i + 1)
            the parent of index i is i/2 (round down)

        Each element of the heap is a vector of size mWidth, and the mKey-th
        element will be used as the key for comparison between elements.

=============================================================================*/

#ifndef __HEAP_H__
#define __HEAP_H__

#include "vector"

class Heap{
    private:
        std::vector< std::vector <long> > mHeapData;
        unsigned mKey, mWidth;
    public:
        Heap(unsigned key = 2, unsigned width = 3);
        void BubbleUp(unsigned);     // Move the added element up the tree
        void BubbleDown(unsigned);   // Remove the root element by moving down
        void Add(std::vector<long>&);// Add one element to the heap
        void Add(long, long, long);  // Add one element to the heap
        std::vector<long> Pop(void); // Remove return the current min value
        std::vector<long> Min(void); // Return min value, the heap is unchanged
};

#endif
