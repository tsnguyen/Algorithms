#ifndef __MERGE_SORT_NAIVE_H__
#define __MERGE_SORT_NAIVE_H__

#include "sort.h"
#include "my_vector_utilities.h"

class MergeSortNaive :public Sort{
    private:
        std::vector<int> mData;
    public:
        void AddElement(int x);
        void Sort(void);
        void ToScreen(void);
};

#endif

