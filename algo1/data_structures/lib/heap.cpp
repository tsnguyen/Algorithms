#include "heap.h"
#include "../../sort/lib/my_vector_utilities.h"
Heap::Heap(void){
    mHeapData.clear();
    HeapElement e0;
    mHeapData.push_back(e0);   // the zeroth element is for place-holder only
}

void Heap::BubbleUp(unsigned index){
    unsigned child = index, parent = child/2;
    while(parent > 0){
        if(mHeapData[child].key < mHeapData[parent].key){
            SwapVectorElements(mHeapData, child, parent);
            child = parent;
            parent = child / 2;
        }
        else
            break;
    }
}

void Heap::BubbleDown(unsigned index){
    unsigned parent = index, child_left, child_right, child;
    unsigned size = mHeapData.size();
    while (parent <= (size - 1) / 2) {
        child_left  = 2 * parent;
        child_right = 2 * parent + 1;
        if ((child_right >= size) || \
                (mHeapData[child_left].key < mHeapData[child_right].key))
            child = child_left;
        else
            child = child_right;
        SwapVectorElements(mHeapData, parent, child);
        parent = child;
    }

    if (child < size - 1){
        SwapVectorElements(mHeapData, child, size - 1);
        BubbleUp(child);
    }
    mHeapData.resize(size - 1);
}

void Heap::Add(HeapElement &element){
    mHeapData.push_back(element);
    BubbleUp(mHeapData.size() - 1);
}

HeapElement Heap::Pop(void){
    HeapElement min = mHeapData[1];
    BubbleDown(1);
    return min;
}

HeapElement Heap::Min(void){
    return mHeapData[1];
}
