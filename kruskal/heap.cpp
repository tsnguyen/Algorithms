#include  "heap.h"

Heap::Heap(unsigned key, unsigned width){
    mKey = key;
    mWidth = width;
    mHeapData.clear();
    std::vector<long> v(mWidth, 0);
    mHeapData.push_back(v);   // the zeroth element is for place - holder only
}

void Heap::BubbleUp(unsigned index){
    unsigned child = index, parent = child/2;
    while(parent >0){
        if(mHeapData[child][mKey] < mHeapData[parent][mKey]){
            mHeapData[child].swap(mHeapData[parent]);
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
                (mHeapData[child_left][mKey] < mHeapData[child_right][mKey]))
            child = child_left;
        else
            child = child_right;
        mHeapData[parent].swap(mHeapData[child]);
        parent = child;
    }

    if (child < size - 1){
        mHeapData[child].swap(mHeapData[size - 1]);
        BubbleUp(child);
    }
    mHeapData.resize(size - 1);
}

void Heap::Add(long node1, long node2, long cost){
    /*
    Add an edge into the heap, with nodes and edge cost.
    */
    long v[3] = {node1, node2, cost};
    std::vector<long> edge(v, v + 3);
    Add(edge);
}
void Heap::Add(std::vector<long> &edge){
    mHeapData.push_back(edge);
    BubbleUp(mHeapData.size() - 1);
}

std::vector<long> Heap::Pop(void){
    std::vector<long> min = mHeapData[1];
    BubbleDown(1);
    return min;
}

std::vector<long> Heap::Min(void){
    return mHeapData[1];
}
