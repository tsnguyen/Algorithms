#ifndef __MERGE_SORT_H__
#define __MERGE_SORT_H__

#include "sort.h"
#include "my_vector_utilities.h"

class MergeSort :public Sort{
    private:
        std::vector<int> mData;
        void Merge(unsigned istart, unsigned imid, unsigned iend);
        void DoMergeSort(unsigned istart, unsigned iend);
    public:
        void AddElement(int x);
        void Sort(void);
        void ToScreen(void);
};

#endif
